#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int contestantsNum = 99, supervisorsNum = 9;  //Number of contestants and supervisors.


class Contestant
{
private:
    string fname;
    string sname;
    string city;
    int debt;
    int weight;
    int number;


public:
    Contestant(){          //Default constructor for Contestant class
        fname = "Default";
        sname = "Default";
        city = "Default";
        debt = 0;
        weight = 0;
        number = 0;
    }
    ~Contestant(){}    //Destructor for Contestant class

    void setFname (string firstName)  //Setters for Contestant class, encapsulation concept
    {
        this->fname = firstName;
    }

    void setSname (string surName)
    {
        this->sname = surName;
    }

    void setCity (string cityName)
    {
        this->city = cityName;
    }

    void setDebt (int debtValue)
    {
        this->debt = debtValue;
    }

    void setWeight (int weightValue)
    {
        this->weight = weightValue;
    }

    void setNumber (int num)
    {
        this->number = num;
    }


    string getFname()        //Getters for Contestant class.
    {
        return this->fname;
    }

    string getSname()
    {
        return this->sname;
    }

    string getCity()
    {
        return this->city;
    }

    int getDebt()
    {
        return this->debt;
    }

    int getWeight()
    {
        return this->weight;
    }

    int getNumber()
    {
        return this->number;
    }


    int squidGame() //Method for the Red Light Green Light game.
    {               //We check if the number of the contestant is even or odd.
        if(this->number % 2 != 0) return 1;    //If it is odd the method returns 1.
        else return 0;                         //If it is even the method returns 0.
    }


    int squidGame(int weight1, int weight2)         //Method for the Tug of War Game.
    {                                               //We check if the total weight of the first team is greater
                                                    //or the total weight of the second team.
        if(weight1 > weight2) return 1;             //It the total weight of first team is greater the method returns 1,
        else if (weight1 < weight2) return 0;       //otherwise it returns 0.
        else if (weight1 == weight2) return -1;     //If both teams have the same weight they are both eliminated.

    }
                                                    //We use the polimorfism concept for the first and second game (overloading).

};


class TugOfWar : public Contestant   //Derived class from Contestant class that we will use for Tug of War game.
{
private:
    int totalWeight;

public:

    TugOfWar()
    {
       totalWeight = 0;
    }

    void setTotalWeight(int weight)
    {
        this->totalWeight = weight;
    }

    int getTotalWeight()
    {
        return this->totalWeight;
    }
};


class Supervisor
{
protected:
    string fname;
    string sname;
    string city;
    int debt;
    int weight;
    string mask;

public:
    Supervisor(){           //Default constructor for Supervisor class
        fname = "Default";
        sname = "Default";
        city = "Default";
        debt = 0;
        weight = 0;
        mask = "Default";
    }

    ~Supervisor(){}  //Destructor for Supervisor class

    virtual void setMask() = 0;
    virtual void setContestants(int x) = 0; //Virtual void functions that will be used in the derived classes.
                                            //Now, the class Supervisor became abstract.


    void setFname (string firstName)  //Setters for Supervisor class.
    {
        this->fname = firstName;
    }

    void setSname (string surName)
    {
        this->sname = surName;
    }

    void setCity (string cityName)
    {
        this->city = cityName;
    }

    void setDebt (int debtValue)
    {
        this->debt = debtValue;
    }

    void setWeight (int weightValue)
    {
        this->weight = weightValue;
    }

    string getFname()        //Getters for Supervisor class.
    {
        return this->fname;
    }

    string getSname()
    {
        return this->sname;
    }

    string getCity()
    {
        return this->city;
    }

    int getDebt()
    {
        return this->debt;
    }

    int getWeight()
    {
        return this->weight;
    }


};

                                           //We create a dervied class for each type of supervisor. (Inheritance concept)

class Circle : public Supervisor
{
private:
    int contestants_index[20];  //We store for each supervisor the index number of each contestant
                                //that he takes care of.
    int remaining_contestants;  //We store the number of remaining contestants for each supervisor, after elimination.

    int money; //We store the amount of money won by each supervisor.
public:

    Circle()
    {
        remaining_contestants = 11;  //Number of contestants for each supervisor.
    }


    void setMask()              //Setters for the type of mask and the index of contestants for
    {                           //each supervisor.
        mask = "circle";
    }

    void setContestants(int x)
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            contestants_index[i] = x;
            x++;
        }
    }

    void setMoney(int sum)   //Setter for money attribute.
    {
        this->money = sum;
    }


    string getMask()        //Getter for mask type.
    {
        return this->mask;
    }


    void getContestants(int v[])  //Getter for the numbers of contestants of each supervisor.
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            v[i] = contestants_index[i];
        }
    }


    int getRemainingContestants()
    {
        return this->remaining_contestants;   //Getter for remaining contestants.
    }

    int getMoney()  //Getter for money attribute.
    {
        return this->money;
    }


};



class Triangle : public Supervisor
{
private:
    int contestants_index[20];
    int remaining_contestants;
    int money;

public:

    Triangle()
    {
        remaining_contestants = 11;
    }

    void setMask()
    {
        mask = "triangle";
    }


    void setContestants(int x)
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            contestants_index[i] = x;
            x++;
        }
    }

    void setMoney(int sum)
    {
        this->money = sum;
    }


    string getMask()
    {
        return this->mask;
    }


    void getContestants(int v[])
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            v[i] = contestants_index[i];
        }
    }

    int getRemainingContestants()
    {
        return this->remaining_contestants;
    }

    int getMoney()
    {
        return this->money;
    }



};



class Rectangle : public Supervisor
{
private:
    int contestants_index[20];
    int remaining_contestants;
    int money;

public:

    Rectangle()
    {
        remaining_contestants = 11;
    }

    void setMask()
    {
        mask = "rectangle";
    }


    void setContestants(int x)
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            contestants_index[i] = x;
            x++;
        }
    }

    void setMoney(int sum)
    {
        this->money = sum;
    }


    string getMask()
    {
        return this->mask;
    }


    void getContestants(int v[])
    {
        for (int i = 0; i < remaining_contestants; i++)
        {
            v[i] = contestants_index[i];
        }
    }


    int getRemainingContestants()
    {
        return this->remaining_contestants;
    }

    int getMoney()
    {
        return this->money;
    }

};



template <class T>
void sortDescending(T arr[], int size_1)   //Template to sort an array of any type in descending order.
{
    int i,j;
    T aux;

    for(i = 0; i < size_1; i++)
    {
        for(j = i+1; j < size_1; j++)
        {
            if(arr[i] < arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}


int Genken(int number1, int number2)    //Function for Genken game. The first number is for the player with the highest index number.
{                                       //The second number is for the the player with the next highest index number.
    if(number1 == 1)                    //If the player with the highest index number wins the function returns 1.
    {                                   //If the player with the next highest index number wins the function returns 0.
        if(number2 == 2) return 0;
        else if(number2 == 3) return 1;
    }
    else if(number1 == 2)
    {
        if(number2 == 1) return 1;
        else if(number2 == 3) return 0;
    }
    else if(number1 == 3)
    {
        if(number2 == 1) return 0;
        else if(number2 == 2) return 1;
    }

    else return -1;
}


int main()
{
    Contestant contestants[200];
    Contestant initial_contestants[200]; //An array of objects in which we store the initial data after random distribution of players.

    Rectangle rectangles[3];
    Triangle triangles[3];
    Circle circles[3];

    int s = 0; //The sum of all players' debt.

    int i = 0, contestantIndex = 1, k = 0; //Index number of each contestant.

    int random[200],i1;   //random[200] is a random array of values from 0 to 107.

    int newitem,size1 = 108;

    srand ( time(NULL) );

    for(i = 0; i < size1; i++)
    {
        bool unique;
        do
        {
          unique = true;
          newitem = rand() % 108;
          for(i1 = 0; i1 < i; i1++)
          {
             if(random[i1] == newitem)
             {
               unique=false;
               break;
             }
          }
        }while(!unique);
           random[i]=newitem;

    }
    //We generate a random array with unique values between 0 and 107.
    //Using these values, we will access a random line from data.txt file
    //in order to set the contestants and supervisors randomly.

    ifstream file;  //Object to read from file.

    file.open("data.txt", ios::in);

    if (file.fail())
        {
            cout << "File was not found\n";
            system("PAUSE");
            exit(1);
        }
          //Check to see if the file can be opened.

    file.close();

    string fname, sname, city, mask;  //Variables which will help us to set classes' attributes.
    int debt, weight, number = 1;


    for(i = 0; i < 99; i++)
    {
        i1 = 0;
        file.open("data.txt", ios::in);
        while(i1 < 108 && file >> fname >> sname >> city >> debt >> weight)
        {
            if (i1 == random[i])
            {
                 contestants[i].setFname(fname);
                 contestants[i].setSname(sname);
                 contestants[i].setCity(city);
                 contestants[i].setDebt(debt);
                 contestants[i].setWeight(weight);
                 contestants[i].setNumber(number);
                 number++;
                 s = s + debt;

                 initial_contestants[i].setFname(fname);
                 initial_contestants[i].setSname(sname);
                 initial_contestants[i].setCity(city);
                 initial_contestants[i].setDebt(debt);
                 initial_contestants[i].setWeight(weight);
                 initial_contestants[i].setNumber(number);
            }
            i1++;
        }
        file.close();

    }
                 //Read data from file into objects of contestant class.


    k = 0;
    for(i = 99; i < 102; i++)
    {
        i1 = 0;
        file.open("data.txt", ios::in);
        while(i1 < 108 && file >> fname >> sname >> city >> debt >> weight)
        {
            if (i1 == random[i])
            {
                 rectangles[k].setFname(fname);
                 rectangles[k].setSname(sname);
                 rectangles[k].setCity(city);
                 rectangles[k].setDebt(debt);
                 rectangles[k].setWeight(weight);
                 rectangles[k].setMask();
                 k++;
            }
            i1++;
        }
        file.close();

    }


                    //Read data from file into objects from each derived class from Supervisor.

    k = 0;
    for(i = 102; i < 105; i++)
    {
        i1 = 0;
        file.open("data.txt", ios::in);
        while(i1 < 108 && file >> fname >> sname >> city >> debt >> weight)
        {
            if (i1 == random[i])
            {
                 triangles[k].setFname(fname);
                 triangles[k].setSname(sname);
                 triangles[k].setCity(city);
                 triangles[k].setDebt(debt);
                 triangles[k].setWeight(weight);
                 triangles[k].setMask();
                 k++;
            }
            i1++;
        }
        file.close();

    }

    k = 0;
    for(i = 105; i < 108; i++)
    {
        i1 = 0;
        file.open("data.txt", ios::in);
        while(i1 < 108 && file >> fname >> sname >> city >> debt >> weight)
        {
            if (i1 == random[i])
            {
                 circles[k].setFname(fname);
                 circles[k].setSname(sname);
                 circles[k].setCity(city);
                 circles[k].setDebt(debt);
                 circles[k].setWeight(weight);
                 circles[k].setMask();
                 k++;
            }
            i1++;
        }
        file.close();

    }



    for(i = 0; i < 3; i++)              //We have 99 contestants and 9 supervisors,
    {                                   //so we allocate 11 contestants for each supervisor.
        rectangles[i].setContestants(contestantIndex);
        contestantIndex = contestantIndex + 11;
    }

    for(i = 0; i < 3; i++)
    {
        triangles[i].setContestants(contestantIndex);
        contestantIndex = contestantIndex + 11;
    }

    for(i = 0; i < 3; i++)
    {
        circles[i].setContestants(contestantIndex);
        contestantIndex = contestantIndex + 11;
    }


    int RedGreenCheck;    //A variable in which we store the result of redLightGreenLight function.
                          //If the result is 1, the player moves forward, if it is 0 he is eliminated.

    int remainingPlayers = 0;   //A variable in which we store how many players are still in the game.


    ofstream wfile;   //Object to write in file.

    wfile.open("redGreenWinners.txt", ios::out);

    if (wfile.fail())
        {
            cout << "File was not found\n";
            system("PAUSE");
            exit(1);
        }            //Check to see if the file can be opened.



    for(i = 0; i < 99; i++)
    {
        RedGreenCheck = contestants[i].squidGame();  //RED LIGHT GREEN LIGHT game.

        if (RedGreenCheck == 1)
        {
            remainingPlayers++;
            fname = contestants[i].getFname();
            sname = contestants[i].getSname();
            city = contestants[i].getCity();
            debt = contestants[i].getDebt();
            weight = contestants[i].getWeight();
            number = contestants[i].getNumber();

            wfile << number << " " << fname << " " << sname << " "
            << city << " " << debt << " " << weight << "\n";

                                   //Data of the winners of the first game will be written in a new file.
        }
    }

    wfile.close();




    ifstream f("redGreenWinners.txt");

    cout << "---- WINNERS OF RED LIGHT GREEN LIGHT ----\n\n";

    if (f.is_open())
        cout << f.rdbuf();

    f.close();    //Display data from the file that contains the winners of the first game.



    int nOfTeamPlayers; //The number of players for each team of Tug of War game.

    nOfTeamPlayers = remainingPlayers / 4;

    int noTeamContestants; // The number of players who are not part of a team and advance to the next game.

    noTeamContestants = remainingPlayers - (4 * nOfTeamPlayers);



    try{
        if(noTeamContestants > 0)
        {
            throw noTeamContestants;
        }
    }
    catch(int noTeamContestants)
    {
        cout << "\n\n----TUG OF WAR----\n"<<
        "There are contestants who are not part of a team.";
    }                //Using exception concept in order to highlight the fact that there are players without a team.
                     //They move forward automatically.



    k = 0;


    int random2[200];   //random2[200] is a random array of values from 0 to "remainingPlayers".

    int size2 = remainingPlayers;

    srand ( time(NULL) );

    for(i = 0; i < size2; i++)
    {
        bool unique;
        do
        {
          unique = true;
          newitem = rand() % remainingPlayers;
          for(i1 = 0; i1 < i; i1++)
          {
             if(random2[i1] == newitem)
             {
               unique = false;
               break;
             }
          }
        }while(!unique);
           random2[i] = newitem;

    }




    file.open("redGreenWinners.txt", ios::in);

    if (file.fail())
        {
            cout << "File was not found\n";
            system("PAUSE");
            exit(1);
        }
          //Check to see if the file can be opened.

    file.close();





    k = 0;

    for(i = 0; i < remainingPlayers; i++)
    {
        i1 = 0;
        file.open("redGreenWinners.txt", ios::in);
        while(i1 < remainingPlayers && file >> number >> fname >> sname >> city >> debt >> weight)
        {
            if (i1 == random2[i])
            {
                 contestants[i].setFname(fname);
                 contestants[i].setSname(sname);
                 contestants[i].setCity(city);
                 contestants[i].setDebt(debt);
                 contestants[i].setWeight(weight);
                 contestants[i].setNumber(number);
            }
            i1++;
        }
        file.close();

    }

                           //Store in the first "remainigPlayers" positions of the contestants array, the playes who are still in the game.
                           //We take the neccessary data from redGreenWinners.txt file.
                           //We store them randomly, in order to create the teams for Tug of War game randomly.
                           //After that, we organise them in teams for Tug of War. When a team reaches a number of "nOfTeamPlayers" contestants
                           //we move forward to the next team.

         TugOfWar teams[4];

         int totalWeights = 0;   //We will calculate the total weight of each team and store it in TugOfWar objects.


         for(i = 0; i < nOfTeamPlayers; i++)
         {
             totalWeights = totalWeights + contestants[i].getWeight();   //Calculate the total wieght of first team.
         }
         teams[0].setTotalWeight(totalWeights);   //Store the total weight in TugOfWar object.

         totalWeights = 0;


         for(i = nOfTeamPlayers; i < 2 * nOfTeamPlayers; i++)
         {
             totalWeights = totalWeights + contestants[i].getWeight();
         }
         teams[1].setTotalWeight(totalWeights);

         totalWeights = 0;



         for(i = 2 * nOfTeamPlayers; i < 3 * nOfTeamPlayers; i++)
         {
             totalWeights = totalWeights + contestants[i].getWeight();
         }
         teams[2].setTotalWeight(totalWeights);

         totalWeights = 0;




         for(i = 3 * nOfTeamPlayers; i < 4 * nOfTeamPlayers; i++)
         {
             totalWeights = totalWeights + contestants[i].getWeight();
         }
         teams[3].setTotalWeight(totalWeights);


                                                          //Using the second method called SquidGame to find out which
                                                          //team has heavier contestans.
                                                          //We store the data of winners in a new file.


        wfile.open("tugOfWarWinners.txt", ios::out);

        if (wfile.fail())
            {
                cout << "File was not found\n";
                system("PAUSE");
                exit(1);
            }            //Check to see if the file can be opened.

        remainingPlayers = noTeamContestants; //We set the remainingPlayers variable to "noTeamContestants" players and
                                              //update it after TugOfWar Game.


         if(teams[0].squidGame(teams[0].getTotalWeight(), teams[1].getTotalWeight()) == 1)
         {
             for(i = 0; i < nOfTeamPlayers; i++)
             {
                 remainingPlayers++;
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";

                                        //Data of the winners of the first game will be written in a new file.
             }
         }else if(teams[0].squidGame(teams[0].getTotalWeight(), teams[1].getTotalWeight()) == 0)
         {
             for(i = nOfTeamPlayers; i < 2 * nOfTeamPlayers; i++)
             {
                 remainingPlayers++;
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";

             }
         }                             //We compare the total weight of two teams at a time and write in the file
                                       //the contestants from the winning team.


         if(teams[0].squidGame(teams[2].getTotalWeight(), teams[3].getTotalWeight()) == 1)
         {
             for(i = 2 * nOfTeamPlayers; i < 3 * nOfTeamPlayers; i++)
             {
                 remainingPlayers++;
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";


             }
         }else if(teams[0].squidGame(teams[2].getTotalWeight(), teams[3].getTotalWeight()) == 0)
         {
             for(i = 3 * nOfTeamPlayers; i < 4 * nOfTeamPlayers; i++)
             {
                 remainingPlayers++;
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";

             }
         }


         for(i = 4 * nOfTeamPlayers; i < 4 * nOfTeamPlayers + noTeamContestants; i++)
         {
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";
         }

         wfile.close();

         ifstream f1("tugOfWarWinners.txt");

         cout << "\n---- WINNERS ----\n\n";

         if (f1.is_open())
             cout << f1.rdbuf();

         f1.close();    //Display data from the file that contains the winners of the second game.



         int random3[200];   //random3[200] is a random array of values from 0 to "remainingPlayers".

         int size3 = remainingPlayers;

         srand ( time(NULL) );

         for(i = 0; i < size3; i++)
         {
             bool unique;
             do
             {
               unique = true;
               newitem = rand() % remainingPlayers;
               for(i1 = 0; i1 < i; i1++)
               {
                  if(random3[i1] == newitem)
                  {
                    unique = false;
                    break;
                  }
               }
             }while(!unique);
                random3[i] = newitem;

         }


         for(i = 0; i < remainingPlayers; i++)
         {
             i1 = 0;
             file.open("tugOfWarWinners.txt", ios::in);

             if (file.fail())
                 {
                     cout << "File was not found\n";
                     system("PAUSE");
                     exit(1);
                 }


         while(i1 < remainingPlayers && file >> number >> fname >> sname >> city >> debt >> weight)
         {
             if (i1 == random3[i])
             {
                  contestants[i].setFname(fname);
                  contestants[i].setSname(sname);
                  contestants[i].setCity(city);
                  contestants[i].setDebt(debt);
                  contestants[i].setWeight(weight);
                  contestants[i].setNumber(number);
             }
             i1++;
         }
         file.close();

     }

                            //Store in the first "remainigPlayers" positions of the contestants array, the playes who are still in the game.
                            //We take the neccessary data from tugOfWarWinners.txt file.
                            //We store them randomly and then organise them in pairs of 2 people for Marbles game.


         noTeamContestants = remainingPlayers % 2;   //The number of players who are not part of a team and advance to the
                                                     //next game.


         try{
             if(noTeamContestants > 0)
             {
                 throw noTeamContestants;
             }
         }
         catch(int noTeamContestants)
         {
             cout << "\n\n----MARBLES----\n"<<
             "There are contestants who are not part of a team.";
         }                //Using exception concept in order to highlight the fact that there are players without a team.
                          //They move forward automatically.


        int number1,number2; //The random numbers that the players will generate.



        wfile.open("marblesWinners.txt", ios::out);

        if (wfile.fail())
            {
                cout << "File was not found\n";
                system("PAUSE");
                exit(1);
            }            //Check to see if the file can be opened.
                         //We will write data of winners in a new file called "marblesWinners.txt";




        int marblesPlayers = remainingPlayers - noTeamContestants;   //The number of contestants in Marbles game.
        remainingPlayers = 0;    //Set the remainingPlayers variable to 0.




         for(i = 0; i < marblesPlayers; i = i + 2)
         {
             number1 = 0;
             number2 = 0;

             while(number1 == number2)
             {
                 srand ( time(NULL) );
                 number1 = rand() % 100;  //Random number between 0 and 99.
                 number2 = rand() % 100;
             }

             if(number1 < number2)
             {
                 remainingPlayers++;
                 fname = contestants[i].getFname();
                 sname = contestants[i].getSname();
                 city = contestants[i].getCity();
                 debt = contestants[i].getDebt();
                 weight = contestants[i].getWeight();
                 number = contestants[i].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";
             }
             else if (number1 > number2)
             {
                 remainingPlayers++;
                 fname = contestants[i+1].getFname();
                 sname = contestants[i+1].getSname();
                 city = contestants[i+1].getCity();
                 debt = contestants[i+1].getDebt();
                 weight = contestants[i+1].getWeight();
                 number = contestants[i+1].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";
             }
         }

         for(i = marblesPlayers; i < marblesPlayers + noTeamContestants; i++)
         {
                 remainingPlayers++;
                 fname = contestants[i+1].getFname();
                 sname = contestants[i+1].getSname();
                 city = contestants[i+1].getCity();
                 debt = contestants[i+1].getDebt();
                 weight = contestants[i+1].getWeight();
                 number = contestants[i+1].getNumber();

                 wfile << number << " " << fname << " " << sname << " "
                 << city << " " << debt << " " << weight << "\n";
         }

         wfile.close();


         ifstream f2("marblesWinners.txt");

         cout << "\n\n---- WINNERS OF MARBLES GAME ----\n\n";

         if (f2.is_open())
             cout << f2.rdbuf();

         f2.close();    //Display data from the file that contains the winners of the third game.



         k = 0;



         file.open("marblesWinners.txt", ios::in);

             if (file.fail())
                 {
                     cout << "File was not found\n";
                     system("PAUSE");
                     exit(1);
                 }
         i = 0;

         while(i < remainingPlayers && file >> number >> fname >> sname >> city >> debt >> weight)
         {
                  contestants[i].setFname(fname);
                  contestants[i].setSname(sname);
                  contestants[i].setCity(city);
                  contestants[i].setDebt(debt);
                  contestants[i].setWeight(weight);
                  contestants[i].setNumber(number);
                  i++;
         }

         file.close();
                              //Store in the first "remainigPlayers" positions of the contestants array, the playes who are still in the game.
                              //We take the neccessary data from marblesWinners.txt file.





                               //Sort the players in descending order by their number and re-store data in marblesWinners.txt file.

        int j,aux[100];         //An array in which we will store the numbers of contestants and sort them in descending order.


        for(i = 0; i < remainingPlayers; i++)
        {
            aux[i] = contestants[i].getNumber();
        }

        sortDescending<int>(aux,remainingPlayers); //Use the template that sorts in descending order the numbers of contestants.


        wfile.open("sortedMarblesWinners.txt", ios::out);

        if (wfile.fail())
            {
                cout << "File was not found\n";
                system("PAUSE");
                exit(1);
            }            //Check to see if the file can be opened.
                         //We will write descending sorted data of winners in a new file called "sortedMarblesWinners.txt";


        for(i = 0; i < remainingPlayers; i++)
        {
            for(j = 0; j < remainingPlayers; j++)
            {
                if(aux[i] == contestants[j].getNumber())  //We start from the highest number from aux array and search the player who has it.
                {                                         //We store his/her data in "sortedMarblesWinners.txt" and continue the procedure.
                    fname = contestants[j].getFname();
                    sname = contestants[j].getSname();
                    city = contestants[j].getCity();
                    debt = contestants[j].getDebt();
                    weight = contestants[j].getWeight();
                    number = contestants[j].getNumber();

                    wfile << number << " " << fname << " " << sname << " "
                    << city << " " << debt << " " << weight << "\n";
                }
            }
        }

        wfile.close();




        file.open("sortedMarblesWinners.txt", ios::in);

             if (file.fail())
                 {
                     cout << "File was not found\n";
                     system("PAUSE");
                     exit(1);
                 }
         i = 0;

         while(i < remainingPlayers && file >> number >> fname >> sname >> city >> debt >> weight)
         {
                  contestants[i].setFname(fname);
                  contestants[i].setSname(sname);
                  contestants[i].setCity(city);
                  contestants[i].setDebt(debt);
                  contestants[i].setWeight(weight);
                  contestants[i].setNumber(number);
                  i++;
         }

         file.close();
                              //Store again in the first "remainigPlayers" positions of the contestants array, the playes who are still in the game.
                              //Now the objects are sorted in descending order by the "number" member of Contestants class.
                              //We take the neccessary data from marblesWinners.txt file.




        for(i = 1; i < remainingPlayers; i++)  //Every time a contestant wins a match his data will be written in SquidGameWINNER.txt file.
        {                                      //Then, the content of the file will be read in contestants[0] object.
                                               //We move forward to the next player and repeat the procedure.
                                               //contestant[0] will have number1 and contestant[i] will have number2.

                                               //If contestant[0] wins, his data will be written in the file, if not, data of contestant[i]
                                               //will be written in the file.
                                               //At the end, the SquidGameWINNER.txt file will contain the winner's data.

            number1 = 0;   //The number of the contestant with highest index number who is still in the game.
            number2 = 0;   //The number of the contestant with the next highest index number who is still in the game.

            while(number1 == number2)
            {
                number1 = (rand() % 3) + 1;   //We generate numbers for the players until they are different.
                number2 = (rand() % 3) + 1;
            }

            if(Genken(number1, number2) == 1)
            {
                wfile.open("SquidGameWINNER.txt", ios::out);  //Winner's data will be stored in SquidGameWINNER.txt file.

                if (wfile.fail())
                {
                      cout << "File was not found\n";
                      system("PAUSE");
                      exit(1);
                }                      //Check to see if the file can be opened.

                fname = contestants[0].getFname();
                sname = contestants[0].getSname();
                city = contestants[0].getCity();
                debt = contestants[0].getDebt();
                weight = contestants[0].getWeight();
                number = contestants[0].getNumber();

                wfile << number << " " << fname << " " << sname << " "
                << city << " " << debt << " " << weight << "\n";

                wfile.close();
            }

            else if(Genken(number1, number2) == 0)
            {
                wfile.open("SquidGameWINNER.txt", ios::out);  //Winner's data will be stored in SquidGameWINNER.txt file.

                if (wfile.fail())
                {
                      cout << "File was not found\n";
                      system("PAUSE");
                      exit(1);
                }                      //Check to see if the file can be opened.

                fname = contestants[i].getFname();
                sname = contestants[i].getSname();
                city = contestants[i].getCity();
                debt = contestants[i].getDebt();
                weight = contestants[i].getWeight();
                number = contestants[i].getNumber();

                wfile << number << " " << fname << " " << sname << " "
                << city << " " << debt << " " << weight << "\n";

                wfile.close();
            }


             file.open("SquidGameWINNER.txt", ios::in);

             if (file.fail())
             {
                 cout << "File was not found\n";
                 system("PAUSE");
                 exit(1);
             }
                    //Check to see if the file can be opened.


             file >> number >> fname >> sname >> city >> debt >> weight;
             contestants[0].setFname(fname);
             contestants[0].setSname(sname);
             contestants[0].setCity(city);
             contestants[0].setDebt(debt);
             contestants[0].setWeight(weight);
             contestants[0].setNumber(number);

             file.close();  //Store the content of SquidGameWINNER.txt file in contestants[0].
        }


        cout << "\n\n\n-----WINNER OF SQUID GAME-----\n\n";

        ifstream f3("SquidGameWINNER.txt");

         if (f3.is_open())
             cout << f3.rdbuf();

         f3.close();


         cout << "\n\n\n\n----SUMMARY----\n\n";

         s = s - contestants[0].getDebt(); //We substract from "s" the winner's debt in order to find out how much money he won.
         cout << "WINNER'S PRIZE: " << s << "$" << endl;


         int index = 0; //Variable that will help us to access the contestants for each supervisor.
         int sum; //Variable to find the amount of money won by each supervisor.
         int s_rectangles = 0, s_triangles = 0, s_circles = 0; //The amount of money won by each team.
         int money[10]; //An array where we will store the amount of money won by each supervisor.
         int p = 0; //Variable used for iteration.

         for(i = 0; i < 3; i++)   //We set the "money" attribute for each supervisor.
         {
             sum = 0;
             for(k = index; k < index + 11; k++) //We
             {
                 sum = sum + initial_contestants[k].getDebt(); //The amount of money won by each supervisor is the sum of his contestants' debts.
                 if(k + 1 == contestants[0].getNumber()) //If the supervisor has the winner he will get his amount of money multiplied by 10.
                 {                                       //We search the contestants in the contestants array from Supervisor class by their number.
                     sum = (contestants[0].getDebt() * 10) - rectangles[i].getDebt();
                     break;
                 }
             }
             rectangles[i].setMoney(sum);
             money[p++] = sum;
             index = index + 11;
             s_rectangles = s_rectangles + sum;
         }

         for(i = 0; i < 3; i++)
         {
             sum = 0;
             for(k = index; k < index + 11; k++)
             {
                 sum = sum + initial_contestants[k].getDebt();
                 if(k + 1 == contestants[0].getNumber())
                 {
                     sum = (contestants[0].getDebt() * 10) - triangles[i].getDebt();
                     break;
                 }
             }

             triangles[i].setMoney(sum);
             money[p++] = sum;
             index = index + 11;
             s_triangles = s_triangles + sum;
         }

         for(i = 0; i < 3; i++)
         {
             sum = 0;
             for(k = index; k < index + 11; k++)
             {
                 sum = sum + initial_contestants[k].getDebt();
                 if(k + 1 == contestants[0].getNumber())
                 {
                     sum = (contestants[0].getDebt() * 10) - triangles[i].getDebt();
                     break;
                 }
             }
             circles[i].setMoney(sum);
             money[p++] = sum;
             index = index + 11;
             s_circles = s_circles + sum;
         }



         sortDescending<int>(money,p); //We sort the money array in descending order using a specific template.


         wfile.open("Supervisors.txt", ios::out); //A file where we will store supervisors' first names, last names and the amount of money won.

         if (wfile.fail())
         {
               cout << "File was not found\n";
               system("PAUSE");
               exit(1);
         }               //Check to see if the file can be opened.


         for(i = 0; i < 9; i++)//We store in Supervisors.txt file each supervisor's data in descending order by the amount of money that they won.
         {
             for(j = 0; j < 3; j++) //We search the values of array "money" in each type of supervisors' object and if we find it we write
             {                      //the object in Supervisors.txt. The array money is sort in descending order by how much money each supervisor won.
                 if(money[i] == rectangles[j].getMoney())
                 {
                     fname = rectangles[j].getFname();
                     sname = rectangles[j].getSname();
                     sum = rectangles[j].getMoney();

                     wfile << fname << " " << sname << " " << sum << "\n";

                 }
             }

             for(j = 0; j < 3; j++)
             {
                 if(money[i] == triangles[j].getMoney())
                 {
                     fname = triangles[j].getFname();
                     sname = triangles[j].getSname();
                     sum = triangles[j].getMoney();

                     wfile << fname << " " << sname << " " << sum << "\n";

                 }
             }

             for(j = 0; j < 3; j++)
             {
                 if(money[i] == circles[j].getMoney())
                 {
                     fname = circles[j].getFname();
                     sname = circles[j].getSname();
                     sum = circles[j].getMoney();

                     wfile << fname << " " << sname << " " << sum << "\n";

                 }
             }


         }

        wfile.close();             //Now the Supervisor.txt file is sorted in descending order by the amount of money
                                   //won by each supervisor.


        cout << endl << endl;
        cout << "~The amount of money won by each supervisor~ \n\n";


        ifstream f4("Supervisors.txt"); //Display the contet of the file. It contains the first names, last names and the amount
                                        //of money won by each supervisor. It is sorted descending by the amount of money.
         if (f4.is_open())
             cout << f4.rdbuf();

         f4.close();



                                                                    //Find the team who won the biggest amount of money.
         if(s_rectangles > s_circles && s_rectangles > s_triangles) cout <<"\nRectangle team won the biggest amount of money: "
                                                                         << s_rectangles << "$\n";
         else if(s_triangles > s_circles && s_triangles > s_rectangles) cout <<"\nTriangle team won the biggest amount of money: "
                                                                             << s_triangles << "$\n";
         else if(s_circles > s_rectangles && s_circles > s_triangles) cout <<"\nCircle team won the biggest amount of money: "
                                                                             << s_circles << "$\n";



    return 0;
}
