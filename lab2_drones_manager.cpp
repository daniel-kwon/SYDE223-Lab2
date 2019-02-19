#include "lab2_drones_manager.hpp"

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
	return 0;
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
  	if(index < 0 || index > size){
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
		else if(index == size - 1){
			insert_back(value);
		}
		else{
			for(int i=0;i<index-1 && i<size;i++){
	      		temp = temp->next;
	    	}
	    	new_value->prev = temp;
	    	temp->next = new_value;
	    	new_value->next = temp->next;
	    	temp->next->prev = new_value;
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
	return true
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
	if(index < 0 || index >= size){
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
			DroneRecord* beforeIndex = first;
	    	DroneRecord* afterIndex = first;
	    	for(int i=0;i<index+1;i++){
	    		if(i<index-1){
	    			beforeIndex = beforeIndex->next;
			}
			afterIndex = afterIndex->next;
	    	}
	    	delete beforeIndex->next;
	    	beforeIndex->next = afterIndex;
	    	afterIndex->prev = beforeIndex;
	    	size--;
		} 
  	}
  	return true;
}

bool DronesManager::remove_front() {
	if(first == NULL){
		return false;
	}
	else{
		DroneRecord* temp = first->next;
	  	delete first;
	  	first = temp;
	}
  	return true;
}

bool DronesManager::remove_back() {
	if(last == NULL){
		return false;
	}
  	else{
  		DroneRecord* temp = last->prev;
  		delete last;
  		last = temp;	
	}
  	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {

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
