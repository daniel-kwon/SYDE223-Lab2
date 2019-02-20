//Daniel Kwon - 20725373
//Judy Zhong - 20719188

#include "lab2_drones_manager.hpp"
#include <iostream> 

using namespace std;

// TODO: Implement all of the listed functions below
DronesManager::DronesManager() {
	size = 0;
	first = NULL;
	last = NULL;
}

DronesManager::~DronesManager() {
	DroneRecord* temp = first;
	while (temp) {
		temp = first->next;
		delete first;
		first = temp;
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	if(lhs.droneID == rhs.droneID && lhs.range == rhs.range && lhs.yearBought == rhs.yearBought && lhs.droneType == rhs.droneType &&
	lhs.manufacturer == rhs.manufacturer && lhs.description == rhs.description && lhs.batteryType == rhs.batteryType){
		return true;
	}
	else{
		return false;
  	}
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if(size > 0){
		return false;
	}
	else {
		return true; 
  	}
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	if(size == 0){
		return DroneRecord(0);
	}
	else{
		DroneRecord* temp = first;
		for(int i = 0; i < index && i < size-1; i++){
			temp = temp->next;
	  }
		return *temp;
	}
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* temp = first;
	for (int j = 0; j < size; j++){
		if (*temp == value){
			return j;
    }
    temp = temp -> next;
  }
  if(size > 0){
    return size;
  }
  else{
    return 0;
  }
}

void DronesManager::print() const {
  	DroneRecord* temp = first;
  	for(int i = 0; i < size; i++){
    	cout<<"Drone ID: "<<temp->droneID<<endl<<"Range:"
    	<<temp->range<<endl<<"Purchase Year: "
    	<<temp->yearBought<<endl<<"Drone Type: "
    	<<temp->droneType<<endl<<"Manufacturer: "
    	<<temp->manufacturer<<endl<<"Description: "<<temp->description<<endl
    	<<"Battery Type: "<<temp->batteryType<<endl;
    	temp = temp->next;
  	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
  	if(index > size){
    	return false;
  	}
  	else{
    	DroneRecord* temp = first;
    	DroneRecord* new_value = new DroneRecord(value);
    	if(first == NULL){
    		first = new_value;
    		last = new_value;
		}
		else if(index==0){
			insert_front(value);
		}
		else{
			for(int i=0;i<index-1;i++){
	      		temp = temp->next;
	    	}
	    	new_value->next = temp->next;
        temp->next->prev = new_value;
        temp->next = new_value;
        new_value->prev = temp;	
	    	size++;
		}
	return true;
  }
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* new_value = new DroneRecord(value);
	if(first == NULL){
		first = new_value;
		last = new_value;
	}
	else{
		DroneRecord* temp = first;
		temp->prev = new_value;
		new_value->next = temp;
		first = new_value;
	}
	size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* new_value = new DroneRecord(value);
	if(last == NULL){
		first = new_value;
		last = new_value;
	}
	else{
		DroneRecord* temp = last;
		temp->next = new_value;
		new_value->prev = temp;
		last = new_value;
	}
	size++;
	return true;
}

bool DronesManager::remove(unsigned int index) {
	if(size<=0||index >= size){
		return false;
  }
	else{
		if(index == 0){
			remove_front();
		}
		else if(index==size-1){
			remove_back();
		}
		else{
      DroneRecord* curr = first;
			for (int i = 0; i < index; i++) {
        curr = curr -> next;
      }
      curr -> prev -> next = curr -> next;
      curr -> next -> prev = curr -> prev;
      size--;
      delete curr;
      curr = NULL;
		} 
  }
  return true;
}

bool DronesManager::remove_front() {
	if(size <= 0){
		return false;
	}
	else{
    if(size == 1){
      delete first;
      first = NULL;
      last = NULL;
    }
    else{
      DroneRecord* temp = first;
      first -> next -> prev = NULL;
	    first = first->next;
      delete temp;
    }
	}
  size--;
  return true;
}

bool DronesManager::remove_back() {
	if(size <= 0){
		return false;
	}
  else{
    if(size ==1){
      delete last;
      last = NULL;
      first = NULL;
    }
    else{
      DroneRecord* temp = last;
  	  last -> prev -> next = last -> next;
      last = temp -> prev;
      delete temp;
    }
	}
  size--;
  return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
  if(index < 0 || index >= size){
    return false;
  }
  else{
    DroneRecord* new_value = new DroneRecord(value);
    DroneRecord* curr = first;
    for(int i=0;i < index; i++){
      curr = curr->next;
    }
    new_value->prev = curr->prev;
    new_value->next = curr->next;    
    if (index == 0){
      first = new_value;
      curr->next->prev = new_value;
    }
    else if(index == size-1){
      last = new_value;
      curr->prev->next = new_value;
    }
    else{
      curr->prev->next = new_value;
      curr->next->prev = new_value;
    }
    delete curr;
    curr = NULL;
  }
  return true;
}

bool DronesManager::reverse_list() {
  DroneRecord* curr = first;
  while(curr != NULL) {
    DroneRecord* after = curr->next;
    curr->next = curr->prev; // reverses prev to next
    curr->prev = after;
    curr = after;
  }
  DroneRecord* temp = first;
  first = last;
  last = temp; // set addresses
	return true;
}

bool DronesManagerSorted::is_sorted_asc() const {
  DroneRecord* temp = first;
  for(int i=0;i<size-1;i++){
    if(temp->droneID > temp->next->droneID){
      return false;
    }
    temp=temp->next;
  }
	return true;
}

bool DronesManagerSorted::is_sorted_desc() const {
  DroneRecord* temp = first;
  for(int i=0;i<size;i++){
    if(temp->droneID < temp->next->droneID)
    return false;
  }
	return true;
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
  DroneRecord* temp = first;
  DroneRecord* value = new DroneRecord(val);
  if(size <=0 || value->droneID < first->droneID){
    insert_front(*value);
  }
  else if(size ==1){
    if(value->droneID >first->droneID){
      insert_back(*value);
    }
    else{
      insert_front(*value);
    }
  }
  else if(value->droneID > last->droneID){
    insert_back(*value);
  }
  else {
    for(int i=0;i<size-1;i++){
      if (temp->droneID < value->droneID && value->droneID < temp->next->droneID){
        insert(*value,i+1);
      }
      temp=temp->next;
    }
    size++;
  }
  return true;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
  DroneRecord* temp = first;
  DroneRecord* value = new DroneRecord(val);
  if(size <=0 || value->droneID > first->droneID){
    insert_front(*value);
  }
  else if(size ==1){
    if(value->droneID <first->droneID){
      insert_back(*value);
    }
    else{
      insert_front(*value);
    }
  }
  else if(value->droneID < last->droneID){
    insert_back(*value);
  }
  else {
    for(int i=0;i<size-1;i++){
      if (temp->droneID > value->droneID && value->droneID > temp->next->droneID){
        insert(*value,i+1);
      }
      temp=temp->next;
    }
    size++;
  }
  return true;
}

void DronesManagerSorted::sort_asc() {
    if (size <= 0) {
        return;
    }
    bool flag = false;
    do {
        flag = false;
        DroneRecord* curr = first;
        while (curr->next != NULL) {
            if (curr->droneID > curr->next->droneID) {
                swap(curr, curr->next);
                flag = true;
            }
            else {
              curr = curr->next; // checking next pair
            }
        }
    } while (flag);
}
    
void DronesManagerSorted::sort_desc() {
  if (size <= 0) {
        return;
  }
  bool flag = false;
  do {
    flag = false;
    DroneRecord* curr = first;
    while (curr->next != NULL) {
      if (curr->droneID < curr->next->droneID) {
        swap(curr, curr->next);
        flag = true;
      }
      else {
        curr = curr->next;
      }
    }

  } while (flag);
}

void DronesManagerSorted::swap(DronesManager::DroneRecord *front, DronesManager::DroneRecord *back) {
  if (front == first && back == last) {
      first = back;
      last = front;
      back->next = front;
      back->prev = NULL;
      front->prev = back;
      front->next = NULL;
  }
  else if (front == first) {
    DroneRecord* temp = back->next;
    back->next->prev = front;
    first = back;
    back->prev = NULL;
    back->next = front;
    front->prev = back;
    front->next = temp;
  }
  else if (back == last) {
    DroneRecord* temp = front->prev;
    front->prev->next = back;
    last = front;
    front->prev = back;
    front->next = NULL;
    back->prev = temp;
    back->next = front;
  }
  else {
    DroneRecord* temp = back->next;
    front->prev->next = back;
    back->next->prev = front;
    back->next = front;
    back->prev = front->prev;
    front->next = temp;
    front->prev = back;
  }
}