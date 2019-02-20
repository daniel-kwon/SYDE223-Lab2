//Daniel Kwon - 20725373
//Judy Zhong - 20719188

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
    bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
    }

	// PURPOSE: insert_front() and insert_back() on zero-element list
    bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
    }

	// PURPOSE: select() and search() work properly
    bool test3() {
		DronesManager manager;
    DronesManager manager1;
		int correct_values[5]= {0,1,2,3,4};
		const int num_elems = 5;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}

		ASSERT_TRUE(manager.search(manager.select(0)) == 0)
    ASSERT_TRUE(manager.search(manager.select(1)) == 1)
    ASSERT_TRUE(manager.search(manager.select(4)) == 4)
		ASSERT_TRUE(manager.search(1000) == manager.get_size())

 		ASSERT_TRUE(manager.select(1) == DronesManager::DroneRecord(1))
     ASSERT_TRUE(manager.select(3) == DronesManager::DroneRecord(3))
    ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(0))
		
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(i))
		}
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	  return true;
    }
    
    // PURPOSE: remove_front() and remove_back() on one-element list
    bool test4() {
		DronesManager manager1, manager2;
		ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(1)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(2)))
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_back())
		
		ASSERT_TRUE(manager1.first == NULL && manager1.last == NULL)
		ASSERT_TRUE(manager2.first == NULL && manager2.last == NULL)
		ASSERT_TRUE(manager1.get_size() == 0 && manager2.get_size() == 0)
		ASSERT_TRUE(manager1.empty() == true && manager2.empty() == true)
		
	  return true;
    }
    
    // PURPOSE: replace() and reverse_list() work properly
    bool test5() {
      DronesManager manager;
		  const int num_elems = 5;
		  for (int i = 0; i < num_elems; i++) {
			  ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		  }

      ASSERT_TRUE(manager.replace(1,5))
      ASSERT_TRUE(manager.replace(2,7))
      ASSERT_TRUE(manager.replace(3,10))
      ASSERT_TRUE(manager.replace(4,15))

      ASSERT_TRUE(manager.first -> droneID == 0)
      ASSERT_TRUE(manager.first ->next-> droneID == 5)
      ASSERT_TRUE(manager.first ->next ->next->droneID == 7)
      ASSERT_TRUE(manager.first ->next ->next->next->droneID == 10)
      ASSERT_TRUE(manager.first ->next ->next->next->next->droneID == 15)

      ASSERT_TRUE(manager.last -> droneID == 15)
      ASSERT_TRUE(manager.last ->prev-> droneID == 10)
      ASSERT_TRUE(manager.last ->prev ->prev->droneID == 7)
      ASSERT_TRUE(manager.last ->prev ->prev->prev->droneID == 5)
      ASSERT_TRUE(manager.last ->prev ->prev->prev->prev->droneID == 0)

      ASSERT_TRUE(manager.reverse_list());

      ASSERT_TRUE(manager.first -> droneID == 15)
      ASSERT_TRUE(manager.first ->next-> droneID == 10)
      ASSERT_TRUE(manager.first ->next ->next->droneID == 7)
      ASSERT_TRUE(manager.first ->next ->next->next->droneID == 5)
      ASSERT_TRUE(manager.first ->next ->next->next->next->droneID == 0)

      ASSERT_TRUE(manager.last -> droneID == 0)
      ASSERT_TRUE(manager.last ->prev-> droneID == 5)
      ASSERT_TRUE(manager.last ->prev ->prev->droneID == 7)
      ASSERT_TRUE(manager.last ->prev ->prev->prev->droneID == 10)
      ASSERT_TRUE(manager.last ->prev ->prev->prev->prev->droneID == 15)
	
		  ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	    return true;
    }
    
    // PURPOSE: insert_front() keeps moving elements forward
    bool test6() {
    	DronesManager manager;
		const int num_elems = 7;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(i)))
			ASSERT_TRUE(manager.get_size() == (i + 1))
			ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(i))
		}	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	  return true;
    }
    
    // PURPOSE: inserting at different positions in the list
    bool test7() {
      DronesManager manager;
		  const int num_elems = 4;
		  for (int i = 0; i < num_elems; i++) {
			  ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		  }
			ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(10),1))
      ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(11),3))
      ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(14),20))
      int correct_values[6] = {0,10,1,11,2,3};
      ASSERT_TRUE(manager.get_size() == 6)
      for (int i = 0; i < 6; i++) {
        ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(correct_values[i]))
      }
      ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(0))
      ASSERT_TRUE(*manager.first -> next == DronesManager::DroneRecord(10))
      ASSERT_TRUE(*manager.first -> next -> next == DronesManager::DroneRecord(1))
      ASSERT_TRUE(*manager.first -> next -> next -> next == DronesManager::DroneRecord(11))
      ASSERT_TRUE(*manager.first -> next -> next -> next -> next == DronesManager::DroneRecord(2))
      ASSERT_TRUE(*manager.first -> next -> next -> next -> next -> next== DronesManager::DroneRecord(3))

      ASSERT_TRUE(*manager.last == DronesManager::DroneRecord(3))
      ASSERT_TRUE(*manager.last -> prev == DronesManager::DroneRecord(2))
      ASSERT_TRUE(*manager.last -> prev -> prev == DronesManager::DroneRecord(11))
      ASSERT_TRUE(*manager.last -> prev -> prev -> prev == DronesManager::DroneRecord(1))
      ASSERT_TRUE(*manager.last -> prev -> prev -> prev -> prev == DronesManager::DroneRecord(10))
      ASSERT_TRUE(*manager.last -> prev -> prev -> prev -> prev -> prev== DronesManager::DroneRecord(0))
		  return true;
    }
    
    // PURPOSE: try to remove too many elements, then add a few elements
    bool test8() {
      DronesManager manager;
      const int num_elems = 4;
		  for (int i = 0; i < num_elems; i++) {
			  ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		  }
      for (int i = 0; i < 2; i++) {
			  ASSERT_TRUE(manager.remove_front())
		  }
      ASSERT_TRUE(manager.select(0) == DronesManager::DroneRecord(2))
      ASSERT_TRUE(manager.select(1) == DronesManager::DroneRecord(3))
      for (int i = 0; i < 2; i++) {
			  ASSERT_TRUE(manager.remove_back())
		  }
      ASSERT_TRUE(manager.get_size()==0)
      for (int i = 0; i < 2; i++) {
			  ASSERT_FALSE(manager.remove(i))
		  }
      const int num_elems2 = 2;
      for (int i = 0; i < num_elems2; i++) {
			  ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		  }
      int correct_values[2] = {0,1};
      for (int i = 0; i < num_elems2; i++) {
        ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(correct_values[i]))
      }
    return true;
    }
    
 	// // PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
    DronesManager manager;
    const int num_elems = 4;
    for (int i = 0; i < num_elems; i++) {
      ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
    }
    ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(0)))
    ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(4)))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(10),1))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(11),3))
    ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(14),20))
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove(1))
		ASSERT_TRUE(manager.remove_back())
    int correct_values[5] = {10,11,1,2,3};
    ASSERT_TRUE(manager.get_size() == 5)
    for (int i = 0; i < 5; i++) {
      ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(correct_values[i]))
    }
		return true;
	}    
	    	
	// PURPOSE: insert into an unsorted list, then sort the list
	bool test10() {
    DronesManagerSorted manager;
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(20)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(12)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(25)))

    ASSERT_TRUE(manager.first -> droneID == 20)
    ASSERT_TRUE(manager.first ->next-> droneID == 12)
    ASSERT_TRUE(manager.first ->next ->next->droneID == 25)

    manager.sort_desc();
    ASSERT_TRUE(manager.first -> droneID == 25)
    ASSERT_TRUE(manager.first ->next-> droneID == 20)
    ASSERT_TRUE(manager.first ->next ->next->droneID == 12)

    ASSERT_TRUE(manager.last -> droneID == 12)
    ASSERT_TRUE(manager.last ->prev-> droneID == 20)
    ASSERT_TRUE(manager.last ->prev ->prev->droneID == 25)

    manager.sort_asc();
    ASSERT_TRUE(manager.first -> droneID == 12)
    ASSERT_TRUE(manager.first ->next-> droneID == 20)
    ASSERT_TRUE(manager.first ->next ->next->droneID == 25)

    ASSERT_TRUE(manager.last -> droneID == 25)
    ASSERT_TRUE(manager.last ->prev-> droneID == 20)
    ASSERT_TRUE(manager.last ->prev ->prev->droneID == 12)

    return true;
	}
	
	// PURPOSE: insert and remove into sorted manager in ascending order
	bool test11() {
    DronesManagerSorted manager;
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(5)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(10)))

    ASSERT_TRUE(manager.insert_sorted_asc(DronesManagerSorted::DroneRecord(0)))
    ASSERT_TRUE(manager.insert_sorted_asc(DronesManagerSorted::DroneRecord(7)))
    ASSERT_TRUE(manager.insert_sorted_asc(DronesManagerSorted::DroneRecord(15)))

    ASSERT_TRUE(manager.first -> droneID == 0)
    ASSERT_TRUE(manager.first ->next-> droneID == 5)
    ASSERT_TRUE(manager.first ->next ->next->droneID == 7)
    ASSERT_TRUE(manager.first ->next ->next->next->droneID == 10)
    ASSERT_TRUE(manager.first ->next ->next->next->next->droneID == 15)


    ASSERT_TRUE(manager.last -> droneID == 15)
    ASSERT_TRUE(manager.last ->prev-> droneID == 10)
    ASSERT_TRUE(manager.last ->prev ->prev->droneID == 7)
    ASSERT_TRUE(manager.last ->prev ->prev->prev->droneID == 5)
    ASSERT_TRUE(manager.last ->prev ->prev->prev->prev->droneID == 0)
		return true;
	}
	
	// PURPOSE: insert and remove into sorted manager in descending order
	bool test12() {
		DronesManagerSorted manager;
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(10)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(5)))

    ASSERT_TRUE(manager.insert_sorted_desc(DronesManagerSorted::DroneRecord(15)))
    ASSERT_TRUE(manager.insert_sorted_desc(DronesManagerSorted::DroneRecord(7)))
    ASSERT_TRUE(manager.insert_sorted_desc(DronesManagerSorted::DroneRecord(0)))

    ASSERT_TRUE(manager.first -> droneID == 15)
    ASSERT_TRUE(manager.first ->next-> droneID == 10)
    ASSERT_TRUE(manager.first ->next ->next->droneID == 7)
    ASSERT_TRUE(manager.first ->next ->next->next->droneID == 5)
    ASSERT_TRUE(manager.first ->next ->next->next->next->droneID == 0)


    ASSERT_TRUE(manager.last -> droneID == 0)
    ASSERT_TRUE(manager.last ->prev-> droneID == 5)
    ASSERT_TRUE(manager.last ->prev ->prev->droneID == 7)
    ASSERT_TRUE(manager.last ->prev ->prev->prev->droneID == 10)
    ASSERT_TRUE(manager.last ->prev ->prev->prev->prev->droneID == 15)
		return true;
	}  
};


#endif
