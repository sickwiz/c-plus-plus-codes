#include<iostream>
#include<string>
using namespace std;
template <typename V>
class mapNode
{
    public:
    string key;
    V value;
    mapNode *next;
    mapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapNode()
    {
        delete next;
    }
};
template <typename V>
class myMap
{
    mapNode<V>** buckets;
    int count;
    int bucketCount;
    public:
    myMap()
    {
        count = 0;
        bucketCount = 5;
        buckets = new mapNode<V>*[bucketCount];
        for(int i=0;i<bucketCount;i++)
            buckets[i] = NULL;
    }
    int getSize()
    {
        return count;
    }
    private:
    void rehash()
    {
        mapNode<V> ** temp = buckets;
        buckets = new mapNode<V>*[2*bucketCount];
        int oldBucketCount = bucketCount;
        bucketCount*=2;
        for(int i=0;i<bucketCount;i++)
        {
            buckets[i] = NULL;
        }
        for(int i = 0;i < oldBucketCount;i++)
        {
            mapNode<V>*head = temp[i];
            // reinsert existing elements in new bucket
            while(head!=NULL)
            {
                string k=head->key;
                V val=head->value;
                insert(k,val);
                head = head->next;
            }
        }
        //delete old bucket
        for(int i = 0;i < oldBucketCount;i++)
        {
             mapNode<V>*head = temp[i];
             delete head;
        }
        delete [] temp;
    }
    int getIndex(string k )
    {
        int coeff = 1;
        int hashCode = 0;
        for(int i=k.length() - 1; i >= 0;i--)
        {
            hashCode += k[i]*coeff;
            hashCode = hashCode%bucketCount;  //so that hashcode doesn't exceed the int limit
            coeff*=37;
            coeff = coeff%bucketCount;       //so that it doesn't exceed the int limit
        }
        return hashCode % bucketCount;
    }

    public:
    double getLoad()
    {
        return (1.0 * count)/bucketCount;
    }
    void insert(string k,V val)
    {
        int index = getIndex(k);
        mapNode<V> *head = buckets[index];
        while(head!=NULL)
        {
            if(head->key == k)
                {
                    head->value = val;  //if key exists,update the value
                    return;
                }
            head = head->next;
        }
        // if key doesn't exist , insert it at the begining
        head = buckets[index];
        mapNode<V> *newNode = new mapNode<V>(k,val);
        newNode->next = head;
        buckets[index] = newNode;
        count++;
        //check load factor <= 0.7
        double loadFactor = (1.0 * count)/bucketCount;
        if(loadFactor > 0.7)
            rehash();   // increase the bucket to twice its size and rehash.
    }
    V getValue(string k)
    {
      int index = getIndex(k);
    //   cout<<endl<<"searching for "<<k<< "at index "<<index<<endl;
      mapNode<V> *head = buckets[index]; 
      while(head != NULL)
      {
          if(head->key == k)
            return head->value;
          head = head->next;
      } 
      return 0;
    }
    V remove(string k)
    {
        int index = getIndex(k);
        mapNode<V> *head = buckets[index];
        mapNode<V>*prev = NULL;
        while(head!=NULL)
        {
            if(head->key == k)
            {
                if(prev == NULL)
                {
                    buckets[index] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V val = head->value;
                head->next = NULL;   // to avoid recursive destruction
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};