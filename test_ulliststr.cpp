#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iostream>  
#include "ulliststr.h" 

using namespace std;


int main(int argc, char* argv[])
{

    ULListStr list;

    cout << "Pushback on empty list" << endl;
    list.push_back("1");
    cout << "Size: " << list.size() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: "  << list.back()  << endl << endl;

    cout << "Pushback on non-empty" << endl;
    list.push_back("2");
    list.push_back("3");
    cout << "Size: " << list.size() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: "  << list.back()  << endl;
    cout << "All vals:" << endl;
    for (size_t i = 0; i < list.size(); ++i) {
        cout <<"  Value "<<i<<": "<< list.get(i) << endl;
    }
    cout << endl;
    cout << "Pushfront" << endl;
    list.push_front("1");
    cout << "Size: " << list.size() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: "  << list.back()  << endl;
    cout << "All vals:" << endl;
    for (size_t i = 0; i < list.size(); ++i) {
        cout <<"  Value "<<i<<": "<< list.get(i) << endl;
    }
    cout << endl;

    cout << "Popback" << endl;
    list.pop_back();
    cout << "Size: " << list.size() << endl;
    cout << "New back: " << list.back() << endl << endl;

    cout << "Pop front" << endl;
    list.pop_front();
    cout << "Size: " << list.size() << endl;
    cout << "New front: " << list.front() << endl << endl;

    cout << "Clear list w popfront" << endl;
    while (!list.empty()) {
        cout << "Front value: " << list.front() << " | Size: " << list.size() << endl;
        list.pop_front();
    }
    cout <<"empty"<< endl;

    cout << "Pushfront empty list" << endl;
    list.push_front("1");
    cout << "Size: " << list.size() << endl;
    cout << "front: " << list.front() << endl;
    cout << "back: "  << list.back()  << endl << endl;

    return 0;

}
