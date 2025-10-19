#include <iostream>
#include <iomanip>
#include <cstddef>
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:
    Buffer() : size(0), data(nullptr) {
        cout << "Constructeur par defaut : buffer vide (" << size << " octet)" << endl;
    }


    Buffer(size_t n) : size(n) {
        data = new unsigned char[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = 0;
        cout << "Constructeur parametre : buffer de " << size << " octet(s) alloue" << endl;
    }

    Buffer(const Buffer& other) : size(other.size) {
        if (size > 0) {
            data = new unsigned char[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
        cout << "Constructeur de copie : buffer copie (" << size << " octet(s))" << endl;
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {

            delete[] data;

            size = other.size;
            if (size > 0) {
                data = new unsigned char[size];
                for (size_t i = 0; i < size; ++i)
                    data[i] = other.data[i];
            } else {
                data = nullptr;
            }
        }
        cout << "Opérateur d'affectation utilise (" << size << " octet(s))" << endl;
        return *this;
    }
    ~Buffer() {
        cout << "Destruction du buffer de " << size << " octet(s)" << endl;
        delete[] data;
    }
    size_t getSize() const {
        return size;
    }

    void fill(unsigned char value) {
        if (data == nullptr) return;
        for (size_t i = 0; i < size; ++i)
            data[i] = value;
    }

    void printHex() const {
        if (size == 0) {
            cout << "(Buffer vide)" << endl;
            return;
        }

        for (size_t i = 0; i < size; ++i) {
            cout << uppercase << hex << setw(2) << setfill('0') << (int)data[i] << " ";
        }
        cout << dec << endl;
    }
};

int main() {
    cout << endl << "Debut du programme " << endl;

    Buffer buf1;
    Buffer buf2(8);
    buf2.fill(0xAA);

    Buffer buf3 = buf2;

    cout << endl << "Contenu des buffers " << endl;
    cout << "Buffer 1 (" << buf1.getSize() << " octet(s)) : ";
    buf1.printHex();

    cout << "Buffer 2 (" << buf2.getSize() << " octet(s)) : ";
    buf2.printHex();

    cout << "Buffer 3 (" << buf3.getSize() << " octet(s)) : ";
    buf3.printHex();
    return 0;
}
