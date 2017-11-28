#include <iostream>
#include <initializer_list>

using namespace std;

class Scan{
    private:
        int m_len;
        int *m_in;
        int *m_out;

    public:
        Scan(int len) : m_len(len) {
            m_in = new int(len);
            m_out = new int(len);

            for(int i = 0; i < len; i++){
                m_in[i]  = 0;
                m_out[i] = 0;
            }
        }

        Scan(initializer_list<int> list) : Scan(list.size()){
            int i = 0;
            for(int item : list){
                m_in[i] = item;
                ++i;
            }
        }

    public:
        void inclusive(){
            int acc = 0;
            for(int i = 0; i < m_len; ++i){
                acc += m_in[i];
                m_out[i] = acc; 
            }
        }

        void exclusive(){
            int acc = 0;
            for(int i = 0; i <  m_len; ++i){
                m_out[i] = acc;
                acc += m_in[i];
            }
        }

        void print(){
            for(int i = 0; i < m_len; ++i){
                cout << m_out[i] << " ";
            }
            cout << endl;
        }

    public:
        ~Scan(){
            delete[] m_in;
            delete[] m_out;
        }
};

int main(){

    Scan scan{1, 3, 6, 8, 10};

    scan.inclusive();
    scan.print();
    scan.exclusive();
    scan.print();

    return 0;
}

