#include "lab2_drones_manager.hpp"


// TODO: Implement all of the listed functions below
DronesManager::DronesManager() {
  DroneRecord();
}

DronesManager::~DronesManager() {
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
  if(lhs.droneID == rhs.droneID && lhs.range == rhs.range && lhs.yearBought == rhs.yearBought && lhs.droneType == rhs.droneType && lhs.manufacturer == rhs.manufacturer && lhs.description == rhs.description && lhs.batteryType == rhs.batteryType){
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
  } // list is not empty

  else {
	  return true; 
  } // list is empty
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
  DroneRecord* curr = first;
  for(int i = 0; i <= index && i < size; i++){
    curr = curr->next;
  }
	return *curr;
}

unsigned int DronesManager::search(DroneRecord value) const {
  DroneRecord* curr = first; // starts at the head of the linked list
  for (int j = 0; j < size; j++)
  {
    if (*curr == value) // check if the current note has a value equal to the value passed in
    {
      return j; // return the index number that stores that value
    }
    curr = curr -> next; // iterates through the linked list (makes curr the next index)
  }
	return 0;
}

void DronesManager::print() const {
  DroneRecord* curr = first;
  for(int i = 0; i < size; i++){
    cout<<"Drone ID: "<<curr->droneID<<endl<<"Range:"
    <<curr->range<<endl<<"Purchase Year: "
    <<curr->yearBought<<endl<<"Drone Type: "
    <<curr->droneType<<endl<<"Manufacturer: "
    <<curr->manufacturer<<endl<<"Description: "<<curr->description<<endl
    <<"Battery Type: "<<curr->batteryType<<endl;
    curr = curr->next;
  }
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
  if(index <= 0 || index >= size){
    return false;
  }
  else{

    DroneRecord* curr = first;
    DroneRecord* new_value = new DroneRecord;
    *new_value = value; // make a copy of the value passed in so that it is usable in this function only, not changing it for the entire code
    for(int i=0;i<index && i<size;i++){
      curr = curr->next; // iterates until curr = index - 1
    }
    value.prev = curr; // uses pointer prev within value to equal index-1
    DroneRecord* oldNext = curr->next; // changing the value of next from index to store new value. it is old because we are about to change it to index+1
    curr->next = new_value; // the new value of (index - 1)'s next
    value.next = oldNext; // next value is inserted in the oldNext, which is the index that was passed in
    oldNext->prev = new_value; // now that oldNext has shifted up by 1, the previous value is now the passed in value (e.g. index 4 is now index 5, and index 4's value is new_value)
    size++;
    return true;
  }
}

bool DronesManager::insert_front(DroneRecord value) {	
  DroneRecord* curr = first; // current node is the first in the list
  DroneRecord* new_value = new DroneRecord; // allocating space
  *new_value = value;
  curr->prev = new_value; // adds new space before head
  value.next = curr; // original head is now the next index
  size++;
  return true;
}

bool DronesManager::insert_back(DroneRecord value) {
  DroneRecord* curr = last;
  DroneRecord* new_value = new DroneRecord;
  *new_value = value;
  curr->next = new_value;
  value.prev = curr;
  size++;
	return true;
}

bool DronesManager::remove(unsigned int index) {
	if(index <= 0 || index >= size){
    return false;
  }
  else{
    DroneRecord* beforeIndex = first;
    DroneRecord* afterIndex = first;
    for(int i=0;i<index+2 && i<size;i++){
      if(i<index){
        beforeIndex = beforeIndex->next;
      }
      afterIndex = afterIndex->next;
    }
    delete beforeIndex->next;
    beforeIndex->next = afterIndex;
    afterIndex->prev = beforeIndex;
    size--;
    return true;
  }
}

bool DronesManager::remove_front() {

  DroneRecord* curr = front;
	return false;
}

bool DronesManager::remove_back() {
  DroneRecord* previous = last->prev;
  delete previous->next;
  previous->next = NULL;
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
    delete curr;
    curr = NULL;
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
  }
  return true;
}

bool DronesManager::reverse_list() {
	return false;
}

bool DronesManagerSorted::is_sorted_asc() const {
	return false;
}

bool DronesManagerSorted::is_sorted_desc() const {
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
	return false;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
	return false;
}

void DronesManagerSorted::sort_asc() {
}
    
void DronesManagerSorted::sort_desc() {
}
