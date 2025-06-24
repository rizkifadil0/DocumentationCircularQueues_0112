
/**
* @mainpage Documentaion Circular Queues
*
* @section Intorduction
* Project ini merupakan project struktur data
* menggunakan struktur queues dengan pendekatan circular arrays.
*
* @section Operations
* Project ini memiliki beberapa opearasi antara lain:
* 1. insert
* 2. delete
* 3. display
*
* @section Cara penggunaan
* Berikut beberapa menu yang bisa digumakan:
* 1. en queue
* 2. de queue
* 3. Display
* 4. Exit
* 
* @author profil
* - nama :Rizki Fadil Budiastanto
* - nim :20240140112
* - kelas:C
* @brief
* @version
* @date 2025-06-24
*
* @copyright Rizki Fadil Budiastanto@umy.ac.id
**/


#include <iostream>
using namespace std;
/**
* @class Queues
* @brief class ini untuk operasi lengkap queus
*
*
*
*/

class Queues {
    private:
    static const int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
    int FRONT; ///< Variable private front untuk menyimpan posisi depan antrean
    int REAR; ///< Variable private rear untuk menyimpan posisi belakang antrean
    int queues_array[15]; ///< Variable private queue_arrray untuk menympan elemen antrian

    public:
        /**
        * @brief Construct a new Queues object
        * set default queues null
        * with front = -1 and rear = -1
        */
    Queues(){
        FRONT = -1;
        REAR = -1;
    }

    /**
    * @brief method untuk memasukkan data dalam antrian
    * data dimasukkan dalam variable queue_array
    */

    void insert (){
        int num; ///< variable num untuk menyimpan nilai
        cout << "Enter a number :";
        cin >> num;
        cout << endl;

        //1.Cek Apakah Antrian Penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)){
            cout << "\nQueues Overflow\n"; //1.0
            return;
        }

        //2. Cek Antrian Apakah Kosong
        if (FRONT == -1){
            FRONT = 0; //2.a
            REAR = 0; //2.b

        }
        else {
            // Jika Rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
            REAR = 0;
            else
            REAR = REAR + 1;

        }
        queues_array[REAR] = num;
    }


    /**
     *@brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam variable queue_array
     */
    void remove (){
        //Cek apakah antrian kosong
        if (FRONT == -1){
            cout << "Queues Underflow\n";
            return;
        }
        cout << "\nThe Element deleted from the queue is : " << queues_array[FRONT] << "\n";

        //Cek Jika Antrian hanya memiliki satu element
        if (FRONT == REAR){
            FRONT = -1;
            REAR = -1;
        }
        else{
            //Jika Element yang dihapus berada di posisi terakhir aray,kembali ke awal array
            if (FRONT == max -1)
            FRONT = 0;
            else
            FRONT = FRONT + 1;
        }
    }
    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variable queue_array
     */

    void display (){
        int front_posisition = FRONT; ///< variable front_posisition untuk menandakan posisi element pertama pada variable front
        int rear_posisition = REAR; ///< variable rear_posisistion untuk menandakan posisi element terakhir pada variable rear

        // Cek Apakah Antrian Kosong
        if (FRONT == -1){
            cout << "Queues is Empty\n";
            return;
        }
        cout << "\n Element in the game are.....\n";

        //Jika front posision iterassi dari dari front hingga rear
        if (front_posisition <= rear_posisition){
            while (front_posisition <= rear_posisition){
                cout << queues_array[front_posisition] << " ";
                front_posisition++;
            }
            cout << endl;
        }
        else{
            //Jika Front Posisition = Rear Position,iterasi dari front hingga akhir array
            while (front_posisition <= max -1){
                cout << queues_array[front_posisition] << "  ";
                front_posisition++;
            }
            
            front_posisition = 0;

             while (front_posisition <= rear_posisition){
                cout << queues_array[front_posisition] << " ";
                front_posisition++;
            }
            cout << endl;

        }
    }
};
/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */

int main (){
    Queues f; ///< objek untuk menggunkan member yang ada pada class queues
    char ch; ///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true){
        try{
            cout << "Menu" <<endl;
            cout << "1. Emplemnt Insert Operation" << endl;
            cout << "2. Implement Delete Operation" << endl; 
            cout << "3. Display Value " <<endl;
            cout << "4. Exit" <<endl;
            cout << "Enter Your Choice (1-4)" <<endl;
            cin >> ch;
            cout <<endl;

            switch (ch){
                case '1':{

                    f.insert();
                    break;
                }
                case '2':{
                    f.remove();
                    break;
                }
                 case '3':{
                    f.display();
                    break;
                }
                 case '4':{
                    
                return 0;
                }
                default:{
                    cout << "Invalid Optional " << endl;
                    break;
                }
            }
        }
        catch (exception &e){
            cout << "Check for the values entered." <<endl;
        }
    }
}