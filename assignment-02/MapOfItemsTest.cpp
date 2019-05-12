#include "MapOfItems.h"

#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostringstream;

bool allItemsAreOkay(const vector<Item> & allItems, vector<Item*> & tour) {
    
    const Item * firstOkayItem = &(allItems[0]);
    const Item * lastOkayItem = &(allItems[allItems.size() - 1]);
    
    for (size_t i = 0; i < tour.size(); ++i) {
        if (tour[i] < firstOkayItem || tour[i] > lastOkayItem) {
            cout << "  * Step " << i << " of the returned tour contains an Item* that does not point to somewhere in the vector of Items stored in MapOfItems";
            return false;
        }
    }
    
    return true;
    
}

int main() {
    
    int retval = 0;
    
    
    MapOfItems m;
    m.addItem(Item(51.75186263338416,-0.3356807902,"48763f26d6b",5));
    m.addItem(Item(51.75166927531987,-0.3455440017,"48763f3b5ef",8));
    m.addItem(Item(51.75293227875113,-0.3363451467,"48763f26e9b",73));
    m.addItem(Item(51.751442536246415,-0.3384676374,"48763f23ff9",117));
    m.addItem(Item(51.750621522352574,-0.3373409116,"48763f21445",142));
    
    {
        cout << "1: Checking that a short tour over a map with five locations, can visit them all\n";
        
        vector<Item*> tour = m.getTour(2.0);
        
        
        if (!allItemsAreOkay(m.getItems(), tour)) {
            
            cout << "  * Failed: all Item pointers in the tour, should point to Items in the vector returned by getItems()\n"; 
            
            ++retval;
            
        } else {
        
            const int basicLength = tour.size();
            
            if (basicLength == 5) {
                cout << "  * Pass - a short tour that visits 5 locations, can visit them all\n";
            } else {
                cout << "  * Fail - should be able to visit exactly 5 locations, but visits " << basicLength << " locations:\n";
                cout << "   i) First point after time 0 is {51.7519, -0.335681, \"48763f26d6b\", 5}.  After this:\n";
                cout << "     - Could go to {51.7517, -0.345544, \"48763f3b5ef\", 8}, arriving at 328.577\n";
                cout << "     - Could go to {51.7529, -0.336345, \"48763f26e9b\", 73}, arriving at 65.6991 then wait for it to appear\n";
                cout << "     - Could go to {51.7514, -0.338468, \"48763f23ff9\", 117}, arriving at 99.051 then wait for it to appear\n";
                cout << "     - Could go to {51.7506, -0.337341, \"48763f21445\", 142}, arriving at 90.3504 then wait for it to appear\n";
                cout << "   ii) Best option is {51.7529, -0.336345, \"48763f26e9b\", 73}, taking time to 73.  After this:\n";
                cout << "     - Could go to {51.7517, -0.345544, \"48763f3b5ef\", 8}, arriving at 381.956\n";
                cout << "     - Could go to {51.7514, -0.338468, \"48763f23ff9\", 117}, arriving at 178.213\n";
                cout << "     - Could go to {51.7506, -0.337341, \"48763f21445\", 142}, arriving at 199.673\n";
                cout << "   iii) Best option is {51.7514, -0.338468, \"48763f23ff9\", 117}, taking time to 178.213.  After this:\n";
                cout << "     - Could go to {51.7517, -0.345544, \"48763f3b5ef\", 8}, arriving at 410.559\n";
                cout << "     - Could go to {51.7506, -0.337341, \"48763f21445\", 142}, arriving at 235.275\n";
                cout << "   iv) Best option is {51.7506, -0.337341, \"48763f21445\", 142}, taking time to 235.275.  After this:\n";
                cout << "     - Could go to {51.7517, -0.345544, \"48763f3b5ef\", 8}, arriving at 509.924\n";
                cout << "   v) Best option is {51.7517, -0.345544, \"48763f3b5ef\", 8}, taking time to 509.924.  Done.\n";

                ++retval;
            }
        }
    }
    
    {
        int shouldBeOne = m.getTour(0.001).size();
        
        if (shouldBeOne == 1) {
            cout << "2: Pass - a tour with speed 0.001 can only visit one place\n";
        } else {
            cout << "2: Fail - a tour with speed 0.001 should only be able to visit one place, but " << shouldBeOne << " were visited\n";
            ++retval;
        }
    }
    
    
    m.addItem(Item(51.75143744449116,-0.3402358672,"48763f2389f",147));
    m.addItem(Item(51.75251803314034,-0.3370846772,"48763f26bed",165));
    m.addItem(Item(51.75308912523243,-0.3391391525,"48763f243cb",175));
    m.addItem(Item(51.74946710411812,-0.3375130472,"48763f21701",180));
    m.addItem(Item(51.74962391496274,-0.3403067809,"48763f23ba5",231));
    m.addItem(Item(51.75359034450039,-0.336818442,"48763f26f2d",297));
    m.addItem(Item(51.75143556184729,-0.3408873362,"48763f23875",312));
    m.addItem(Item(51.75383602189929,-0.3373798427,"48763f26893",334));
    m.addItem(Item(51.753336665789924,-0.3390490926,"48763f24253",344));
    m.addItem(Item(51.75184227425975,-0.342753794,"48763f2498b",400));
    m.addItem(Item(51.75135448495597,-0.3404209931,"48763f23885",411));
    m.addItem(Item(51.74839218628601,-0.3387097451,"48763f222ed",424));
    m.addItem(Item(51.750701810057386,-0.3380863833,"48763f2159b",426));
    m.addItem(Item(51.74897391949844,-0.3370417924,"48763f2175b",451));
    m.addItem(Item(51.751433675577154,-0.3415388137,"48763f237e3",464));
    m.addItem(Item(51.751111779002045,-0.3388358808,"48763f23fbd",467));
    m.addItem(Item(51.752680214539055,-0.3380173266,"48763f26a19",508));
    m.addItem(Item(51.75218246623874,-0.3391281142,"48763f24101",641));
    m.addItem(Item(51.75176605816747,-0.3406121655,"48763f2479f",657));
    m.addItem(Item(51.75160844917865,-0.3380973874,"48763f26ab1",666));
    m.addItem(Item(51.751040794618945,-0.3348333568,"48763f20d11",667));
    m.addItem(Item(51.751667363113846,-0.3461955461,"48763f3b63d",668));
    m.addItem(Item(51.749220112028645,-0.3374169976,"48763f2170d",691));
    m.addItem(Item(51.75141872868837,-0.346657863,"48763f3c829",772));
    m.addItem(Item(51.752262475935396,-0.3399667281,"48763f246d1",783));
    m.addItem(Item(51.752996470255205,-0.3426749168,"48763f24ea5",790));
    m.addItem(Item(51.75111605072359,-0.3373469005,"48763f214e9",811));
    m.addItem(Item(51.75235078779228,-0.3379202607,"48763f26a43",825));
    m.addItem(Item(51.750710844465225,-0.3349224478,"48763f20da3",891));
    m.addItem(Item(51.749220910993635,-0.3371378372,"48763f2173f",903));
    m.addItem(Item(51.75087595155126,-0.3348313754,"48763f20d09",935));
    m.addItem(Item(51.75259992407921,-0.3372718036,"48763f26bc3",937));
    m.addItem(Item(51.74995117345432,-0.34114837,"48763f23a0f",956));
    m.addItem(Item(51.751595818870385,-0.3424715373,"48763f249e7",985));

    {
        vector<Item*> tour = m.getTour(2.5);
        
        if (tour.size() == 34) {
            cout << "3: Pass - a larger tour correctly managed to visit 34 locations\n";
        } else {
            cout << "3: Fail - a larger tour should have visited 34 locations, but actually visited " << tour.size() << std::endl;
            ++retval;
        }
    }
    
    return retval;
}
