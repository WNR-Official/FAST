#ifndef HSH_H
#define HSH_H
template<class DT>
class Hashtable{
    private:
        int size;
        DT* table;
    public:
        Hashtable(int s);
        bool store(DT key);
        bool search(DT key);
         

};

    template<class dt>
    Hashtable<dt>::Hashtable(int s){
        size=s;
        table=new dt[size];
        for(int i=0;i<size;i++){
            table[i]=-99; 
        }
    }
    template <class dt>
    bool Hashtable<dt>:: store(dt key){
     int location = key % size;
     while (table [location] != -99){
        location =(location + 1) % size ;
        }
        if (table[location]==-99){
            table[location]=key;
            return true;
        }
        else{
            return false;
        }

    }

    template <class dt>
    bool Hashtable<dt> :: search(dt key){
        int location = key % size;
        while (table [location] != -99){
            if (table[location]==key){
                return true;
            }
            location =(location + 1) % size ;
        }
        return false;
    }

#endif // HSH_H