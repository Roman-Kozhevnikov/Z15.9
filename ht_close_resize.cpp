#include "ht_close_resize.h"

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array = new Pair[mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}

int HashTable::hash_func(Login _log, int offset) {
    int val = strlen(_log);
    const double A = 0.7;
    const int M = mem_size;
    return (int(M * (A * val - int(A * val))) + offset * offset) % mem_size;    
}

//int HashTable::hash_func(Login _log, int offset) {
//    
//    int sum = 0, i = 0;
//    for (; i < strlen(_log); i++) {
//        sum += _log[i];
//    }
//    
//    return (sum % mem_size + offset * offset) % mem_size;
//}

void HashTable::resize() {
    
    Pair* array_save = array; 
    int oldSize = mem_size;

    mem_size *= 2;  
    count = 0;     
    array = new Pair [mem_size];     

    for (int i = 0; i < oldSize; i++) {
        
        if (array_save[i].status == enPairStatus::engaged)
            
            add(array_save[i].log, array_save[i].dg);           
            
    }
    

    delete[] array_save;
}

void HashTable::add(Login _log, Digest _dg) {
    int index = -1, i = 0;
    
    for (;i < mem_size; i++) {
        index = hash_func(_log, i);
        if (array[index].status == enPairStatus::free) {
            
            break;
        }
    }

    if (i >= mem_size) {
        resize();
        add(_log, _dg);
    }
    else {
        array[index] = Pair(_log, _dg);
        count++;
    }
}

void HashTable::del(Login _log) {
   
    int index = -1, i = 0;
    
    for (;i < mem_size; i++) {
        index = hash_func(_log, i);
        if (array[index].status == enPairStatus::engaged &&
            !strcmp(array[index].log, _log)) {
            array[index].status = enPairStatus::deleted;
            count--;
            return;
        }
        else if (array[index].status == enPairStatus::free) {
            return;
        }
    }
}

int HashTable::find(Login _log) {

    for (int i = 0;i < mem_size; i++) {
        int index = hash_func(_log, i);
        if (array[index].status == enPairStatus::engaged &&
            !strcmp(array[index].log, _log)) {
            return 1;
        }
        else if (array[index].status == enPairStatus::free) {
            return -1;
        }
    }
    return -1;
}

uint* HashTable::findbyData(Login _log) {

    for (int i = 0;i < mem_size; i++) {
        int index = hash_func(_log, i);
        if (array[index].status == enPairStatus::engaged &&
            !strcmp(array[index].log, _log)) {
            return array[index].dg;
        }
        else if (array[index].status == enPairStatus::free) {
            return nullptr;
        }
    }
    return nullptr;
}

void HashTable::show() const
{
    for (int i = 0;i < mem_size; i++) {
        
        if (array[i].status == enPairStatus::engaged)
            
            std::cout << array[i].log << " ";        
            array[i].dg_show();
            std::cout << endl;
        }

}