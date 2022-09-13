
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <limits>

using namespace std;

// class player
class Player
{
private:
        int id;
        string name;
        int birthYear;
        int matchPlayed;
        int runsScored;
        int wicketsTaken;
        int catchesTaken;

public:
        bool isNumber(const string &str)
        {
                for (char const &c : str)
                {
                        if (std::isdigit(c) == 0)
                                return false;
                }
                return true;
        }

        /*
         * This function takes input from user about Player Details
         * The input taken by this function is stored in the File using writeFile() function
         */
        bool input()
        {
                string str;
                bool validInput = true;
                cout << "Enter player id : " << endl;
                cin >> str;

                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        id = stoi(str);
                }

                cout << "Enter the name of player: " << endl;
                cin >> name;

                cout << "\nEnter player birth year: " << endl;
                cin >> str;
                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        birthYear = stoi(str);
                }

                cout << "\nEnter matched played: " << endl;
                cin >> str;

                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        matchPlayed = stoi(str);
                }

                cout << "\nEnter runs scored: " << endl;
                cin >> runsScored;
                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        runsScored = stoi(str);
                }

                cout << "\nEnter wickets taken: " << endl;
                cin >> wicketsTaken;
                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        wicketsTaken = stoi(str);
                }

                cout << "\nEnter catches taken: " << endl;
                cin >> catchesTaken;
                if (!isNumber(str))
                {
                        cout << "Not a valid number" << endl;
                        validInput = false;
                        return validInput;
                }
                else
                {
                        catchesTaken = stoi(str);
                }
                return validInput;
        }

        void inputUpdate(int updateId)
        {

                id = updateId;
                cout << "Enter the name of player: " << endl;
                cin >> name;
                cout << "\nEnter player birth year: " << endl;
                cin >> birthYear;
                cout << "\nEnter matched played: " << endl;
                cin >> matchPlayed;
                cout << "\nEnter runs scored: " << endl;
                cin >> runsScored;
                cout << "\nEnter wickets taken: " << endl;
                cin >> wicketsTaken;
                cout << "\nEnter catches taken: " << endl;
                cin >> catchesTaken;
        }

        void output()
        {
                cout << "\nPlayer Details: \n";
                cout << "Id-->" << id << endl;
                cout << "Name-->" << name << endl;
                cout << "Birth year-->" << birthYear << endl;
                cout << "Matched played-->" << matchPlayed << endl;
                cout << "Runs scored-->" << runsScored << endl;
                cout << "Wickets taken-->" << wicketsTaken << endl;
                cout << "Catched taken-->" << catchesTaken << endl;
        }

        string getname()
        {
                return name;
        }

        int getid()
        {
                return id;
        }

        int getBirthYear()
        {
                return birthYear;
        }

        int getMatchesPlayed()
        {
                return matchPlayed;
        }

        int getRunsScored()
        {
                return runsScored;
        }

        int getWicketsTaken()
        {
                return wicketsTaken;
        }

        int getCatchesTaken()
        {
                return catchesTaken;
        }

        void setname(string _name)
        {
                name = _name;
        }

        void setid(int _id)
        {
                id = _id;
        }

        void setBirthYear(int _yr)
        {
                birthYear = _yr;
        }

        void setMatchesPlayed(int match)
        {
                matchPlayed = match;
        }

        void setRunsScored(int run)
        {
                runsScored = run;
        }

        void setWicketsTaken(int wickets)
        {
                wicketsTaken = wickets;
        }

        void setCatchedTaken(int catches)
        {
                catchesTaken = catches;
        }

}; // End of Class file

// end class player

void displayPlayer(Player *player)
{
        cout << endl;
        cout << player->getid() << "\t";
        cout << player->getname() << "\t";
        cout << player->getBirthYear() << "\t";
        cout << player->getMatchesPlayed() << "\t";
        cout << player->getRunsScored() << "\t";
        cout << player->getWicketsTaken() << "\t";
        cout << player->getCatchesTaken() << "\t";
        cout << endl;
}

// B + tree implementation

const int MAX = 4;
const int MIN = 2;
struct btnode
{
        int count;
        int value[MAX + 1];
        btnode *child[MAX + 1];
};
class btree
{
private:
        btnode *root;

public:
        btree();
        btnode *getRoot()
        {
                return root;
        }
        void insert(int val);
        int setval(int val, btnode *n, int *p, btnode **c);
        static btnode *search(int val, btnode *root, int *pos);
        static int searchnode(int val, btnode *n, int *pos);
        void fillnode(int val, btnode *c, btnode *n, int k);
        void split(int val, btnode *c, btnode *n,
                   int k, int *y, btnode **newnode);
        void del(int val);
        int delhelp(int val, btnode *root);
        void clear(btnode *root, int k);
        void copysucc(btnode *root, int i);
        void restore(btnode *root, int i);
        void rightshift(int k);
        void leftshift(int k);
        void merge(int k);
        void show();
        void save(string fileName);
        void saveToFile(btnode *root, ofstream *file);
        static void display(btnode *root);
        static void deltree(btnode *root);
        void runsScored(int runs);
        void catchesTaken(int catches);
        void wicketsTaken(int wickets);
        void checkNames(string name);
        Player *getPlayerData(string fileName);
        int checkNodesRunsScored(btnode *, int);
        int checkNodesWicketsTaken(btnode *, int);
        int checkNodesCatchesTaken(btnode *, int);
        int checkNodesName(btnode *, string);
        ~btree();
};

btree ::btree()
{
        root = NULL;
}
void btree ::insert(int val)
{
        int i;
        btnode *c, *n;
        int flag;
        flag = setval(val, root, &i, &c);
        if (flag)
        {
                n = new btnode;
                n->count = 1;
                n->value[1] = i;
                n->child[0] = root;
                n->child[1] = c;
                root = n;
        }
}
int btree ::setval(int val, btnode *n, int *p, btnode **c)
{
        int k;
        if (n == NULL)
        {
                *p = val;
                *c = NULL;
                return 1;
        }
        else
        {
                if (searchnode(val, n, &k))
                        cout << endl
                             << "Key value already exists." << endl;
                if (setval(val, n->child[k], p, c))
                {
                        if (n->count < MAX)
                        {
                                fillnode(*p, *c, n, k);
                                return 0;
                        }
                        else
                        {
                                split(*p, *c, n, k, p, c);
                                return 1;
                        }
                }
                return 0;
        }
}
btnode *btree ::search(int val, btnode *root, int *pos)
{
        if (root == NULL)
                return NULL;
        else
        {
                if (searchnode(val, root, pos))
                        return root;
                else
                        return search(val, root->child[*pos], pos);
        }
}
int btree ::searchnode(int val, btnode *n, int *pos)
{
        if (val < n->value[1])
        {
                *pos = 0;
                return 0;
        }
        else
        {
                *pos = n->count;
                while ((val < n->value[*pos]) && *pos > 1)
                        (*pos)--;
                if (val == n->value[*pos])
                        return 1;
                else
                        return 0;
        }
}
void btree ::fillnode(int val, btnode *c, btnode *n, int k)
{
        int i;
        for (i = n->count; i > k; i--)
        {
                n->value[i + 1] = n->value[i];
                n->child[i + 1] = n->child[i];
        }
        n->value[k + 1] = val;
        n->child[k + 1] = c;
        n->count++;
}
void btree ::split(int val, btnode *c, btnode *n,
                   int k, int *y, btnode **newnode)
{
        int i, mid;

        if (k <= MIN)
                mid = MIN;
        else
                mid = MIN + 1;

        *newnode = new btnode;

        for (i = mid + 1; i <= MAX; i++)
        {
                (*newnode)->value[i - mid] = n->value[i];
                (*newnode)->child[i - mid] = n->child[i];
        }

        (*newnode)->count = MAX - mid;
        n->count = mid;

        if (k <= MIN)
                fillnode(val, c, n, k);
        else
                fillnode(val, c, *newnode, k - mid);

        *y = n->value[n->count];
        (*newnode)->child[0] = n->child[n->count];
        n->count--;
}
void btree ::del(int val)
{
        btnode *temp;

        if (!delhelp(val, root))
                cout << endl
                     << "Value " << val << " not found.";
        else
        {
                if (root->count == 0)
                {
                        temp = root;
                        root = root->child[0];
                        delete temp;
                }
        }
}
int btree ::delhelp(int val, btnode *root)
{
        int i;
        int flag;

        if (root == NULL)
                return 0;
        else
        {
                flag = searchnode(val, root, &i);
                if (flag)
                {
                        if (root->child[i - 1])
                        {
                                copysucc(root, i);
                                flag = delhelp(root->value[i], root->child[i]);
                                if (!flag)
                                        cout << endl
                                             << "Value " << val << " not found.";
                        }
                        else
                                clear(root, i);
                }
                else
                        flag = delhelp(val, root->child[i]);
                if (root->child[i] != NULL)
                {
                        if (root->child[i]->count < MIN)
                                restore(root, i);
                }
                return flag;
        }
}
void btree ::clear(btnode *root, int k)
{
        int i;
        for (i = k + 1; i <= root->count; i++)
        {
                root->value[i - 1] = root->value[i];
                root->child[i - 1] = root->child[i];
        }
        root->count--;
}
void btree ::copysucc(btnode *root, int i)
{
        btnode *temp = root->child[i];

        while (temp->child[0])
                temp = temp->child[0];

        root->value[i] = temp->value[1];
}
void btree ::restore(btnode *root, int i)
{
        if (i == 0)
        {
                if (root->child[1]->count > MIN)
                        leftshift(1);
                else
                        merge(1);
        }
        else
        {
                if (i == root->count)
                {
                        if (root->child[i - 1]->count > MIN)
                                rightshift(i);
                        else
                                merge(i);
                }
                else
                {
                        if (root->child[i - 1]->count > MIN)
                                rightshift(i);
                        else
                        {
                                if (root->child[i + 1]->count > MIN)
                                        leftshift(i + 1);
                                else
                                        merge(i);
                        }
                }
        }
}
void btree ::rightshift(int k)
{
        int i;
        btnode *temp;

        temp = root->child[k];

        for (i = temp->count; i > 0; i--)
        {
                temp->value[i + 1] = temp->value[i];
                temp->child[i + 1] = temp->child[i];
        }

        temp->child[1] = temp->child[0];
        temp->count++;
        temp->value[1] = root->value[k];
        temp = root->child[k - 1];
        root->value[k] = temp->value[temp->count];
        root->child[k]->child[0] = temp->child[temp->count];
        temp->count--;
}
void btree ::leftshift(int k)
{
        btnode *temp;

        temp = root->child[k - 1];
        temp->count++;
        temp->value[temp->count] = root->value[k];
        temp->child[temp->count] = root->child[k]->child[0];
        temp = root->child[k];
        root->value[k] = temp->value[1];
        temp->child[0] = temp->child[1];
        temp->count--;
        for (int i = 1; i <= temp->count; i++)
        {
                temp->value[i] = temp->value[i + 1];
                temp->child[i] = temp->child[i + 1];
        }
}
void btree ::merge(int k)
{
        btnode *temp1, *temp2;
        temp1 = root->child[k];
        temp2 = root->child[k - 1];
        temp2->count++;
        temp2->value[temp2->count] = root->value[k];
        temp2->child[temp2->count] = root->child[0];
        for (int i = 1; i <= temp1->count; i++)
        {
                temp2->count++;
                temp2->value[temp2->count] = temp1->value[i];
                temp2->child[temp2->count] = temp1->child[i];
        }
        for (int i = k; i < root->count; i++)
        {
                root->value[i] = root->value[i + 1];
                root->child[i] = root->child[i + 1];
        }
        root->count--;
        delete temp1;
}
void btree ::show()
{
        display(root);
}

void btree ::display(btnode *root)
{
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        display(root->child[i]);
                        cout << root->value[i + 1] << "\t";
                }
                display(root->child[i]);
        }
}

void btree ::saveToFile(btnode *root, ofstream *file)
{
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        saveToFile(root->child[i], file);
                        *file << root->value[i + 1] << "\n";
                }
                saveToFile(root->child[i], file);
        }
}

Player *btree ::getPlayerData(string fileName)
{
        Player *player = new Player();
        std::ifstream file(fileName);
        int lineCount = 1;

        if (file.is_open())
        {
                cout << endl;
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        switch (lineCount)
                        {
                        case 1:
                        {
                                int num = stoi(line);
                                player->setid(num);
                                break;
                        }

                        case 2:
                        {
                                player->setname(line);
                                break;
                        }

                        case 3:
                        {
                                int num = stoi(line);
                                player->setBirthYear(num);
                                break;
                        }

                        case 4:
                        {
                                int num = stoi(line);
                                player->setMatchesPlayed(num);
                                break;
                        }

                        case 5:
                        {
                                int num = stoi(line);
                                player->setRunsScored(num);
                                break;
                        }

                        case 6:
                        {
                                int num = stoi(line);
                                player->setWicketsTaken(num);
                                break;
                        }

                        case 7:
                        {
                                int num = stoi(line);
                                player->setCatchedTaken(num);
                                break;
                        }

                        default:
                                break;
                        }
                        lineCount++;
                }
                file.close();
        }

        return player;
}

int btree::checkNodesName(btnode *root, string name)
{
        int returnValue = 0;
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        checkNodesName(root->child[i], name);
                        string fileName = "./PlayerDataBase/" + to_string(root->value[i + 1]) + ".dat";
                        Player *player = getPlayerData(fileName);
                        if (player->getname().compare(name) == 0)
                        {
                                displayPlayer(player);
                                returnValue = 1;
                        }
                }
                checkNodesName(root->child[i], name);
        }
        return returnValue;
}

int btree::checkNodesRunsScored(btnode *root, int runsScored)
{
        int returnValue = 0;
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        checkNodesRunsScored(root->child[i], runsScored);
                        string fileName = "./PlayerDataBase/" + to_string(root->value[i + 1]) + ".dat";
                        Player *Player = getPlayerData(fileName);
                        if (Player->getRunsScored() >= runsScored)
                        {
                                displayPlayer(Player);
                                returnValue = 1;
                        }
                }
                checkNodesRunsScored(root->child[i], runsScored);
        }
        return returnValue;
}

int btree::checkNodesCatchesTaken(btnode *root, int catches)
{
        int returnValue = 0;
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        checkNodesCatchesTaken(root->child[i], catches);
                        string fileName = "./PlayerDataBase/" + to_string(root->value[i + 1]) + ".dat";
                        Player *player = getPlayerData(fileName);
                        if (player->getCatchesTaken() >= catches)
                        {
                                displayPlayer(player);
                                returnValue = 1;
                        }
                }
                checkNodesCatchesTaken(root->child[i], catches);
        }
        return returnValue;
}

int btree::checkNodesWicketsTaken(btnode *root, int wickets)
{
        int returnValue = 0;
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        checkNodesWicketsTaken(root->child[i], wickets);
                        string fileName = "./PlayerDataBase/" + to_string(root->value[i + 1]) + ".dat";
                        Player *player = getPlayerData(fileName);
                        if (player->getWicketsTaken() >= wickets)
                        {
                                displayPlayer(player);
                                returnValue = 1;
                        }
                }
                checkNodesWicketsTaken(root->child[i], wickets);
        }
        return returnValue;
}

void btree::runsScored(int runs)
{
        checkNodesRunsScored(root, runs);
}
void btree::catchesTaken(int catches)
{
        checkNodesCatchesTaken(root, catches);
}
void btree::wicketsTaken(int wickets)
{
        checkNodesWicketsTaken(root, wickets);
}
void btree::checkNames(string name)
{
        checkNodesName(root, name);
}

void btree::save(string fileName)
{
        ofstream fout;
        fout.open(fileName);
        saveToFile(root, &fout);
        fout.close();
}

void btree ::deltree(btnode *root)
{
        int i = 0;
        if (root != NULL)
        {
                for (i = 0; i < root->count; i++)
                {
                        deltree(root->child[i]);
                        delete (root->child[i]);
                }
                deltree(root->child[i]);
                delete (root->child[i]);
        }
}

btree ::~btree()
{
        deltree(root);
}
// end of B + tree implementation

btree playerIdIndexTree;
btree catchesIndexTree;
btree runsScoredIndexTree;
btree wicketsTakenIndexTree;

/*
 * This function is used to write the details in the file
 * It takes details of class instance and append that into the file
 *
 */
void writeInFile(Player player)
{

        string delimeter = "\n";
        ofstream fout;
        string fileName = "./PlayerDataBase/" + to_string(player.getid()) + ".dat";
        fout.open(fileName, ios::out);
        fout << player.getid();
        fout << delimeter;
        fout << player.getname();
        fout << delimeter;
        fout << player.getBirthYear();
        fout << delimeter;
        fout << player.getMatchesPlayed();
        fout << delimeter;
        fout << player.getRunsScored();
        fout << delimeter;
        fout << player.getWicketsTaken();
        fout << delimeter;
        fout << player.getCatchesTaken();
        fout.close();
}

void displayPlayer(string fileName)
{
        std::ifstream file(fileName);
        int lineCount = 1;

        if (file.is_open())
        {
                cout << endl;
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        cout << line << "\t";
                }
                file.close();
        }
}

void deleteInRecords()
{
        int playerId;
        cout << "Enter the palyer id: ";
        cin >> playerId;
        int found;
        btnode *node = playerIdIndexTree.search(playerId, playerIdIndexTree.getRoot(), &found);
        if (node != NULL)
        {
                string fileName = "./PlayerDataBase/" + to_string(playerId) + ".dat";
                cout << "Deleted record:\n";
                displayPlayer(fileName);
                remove(fileName.c_str());
                playerIdIndexTree.del(playerId);
        }
        else
        {
                cout << "No Record Found For Player Id:" << playerId << ": " << endl;
        }
}

void searchRecords(int choice)
{

        int playerId;
        string playerName;

        if (choice == 1)
        {
                cout << "Enter the palyer id: ";
                cin >> playerId;
                int found;
                btnode *node = playerIdIndexTree.search(playerId, playerIdIndexTree.getRoot(), &found);
                if (node != NULL)
                {
                        string fileName = "./PlayerDataBase/" + to_string(playerId) + ".dat";
                        displayPlayer(fileName);
                }
                else
                {
                        cout << "No Record Found For Player Id:" << playerId << ": " << endl;
                }
        }
        else if (choice == 2)
        {
                string name;
                cout << endl;
                cout << "Enter the palyer name: ";
                cin >> name;
                playerIdIndexTree.checkNames(name);
        }
}

void searchRunsScored()
{
        int runs;
        cout << endl;
        cout << "Enter the runs scored: ";
        cin >> runs;
        playerIdIndexTree.runsScored(runs);
}

void searchWicketsTaken()
{
        int wicketsTaken;
        cout << endl;
        cout << "Enter the wickets taken: ";
        cin >> wicketsTaken;
        playerIdIndexTree.wicketsTaken(wicketsTaken);
}
void searchCatchesTaken()
{
        int catches;
        cout << endl;
        cout << "Enter the catches taken: ";
        cin >> catches;
        playerIdIndexTree.catchesTaken(catches);
}

void updateRecord()
{
        int playerId;
        cout << endl;
        cout << "Enter the player id to update:" << endl;
        cin >> playerId;
        int found;
        btnode *node = playerIdIndexTree.search(playerId, playerIdIndexTree.getRoot(), &found);
        if (node == NULL)
        {
                cout << endl;
                cout << "No Player record found with the id";
        }
        else
        {
                Player player;
                player.inputUpdate(playerId);
                writeInFile(player);
        }
}

/*
 * This function is used to completely delete the Player Database
 * It asks for re-confirmation from user
 * If the user press "Y" it completely clears the Player's record
 */

void clearCompleteDatabase()
{
        int x;
        cout << "Do you want to delete the complete database of Players...?\n Press 1 to confirm: ";
        cin >> x;

        if (x == 1)
        {
                remove("PlayersRecord.txt");             // Delete the file(Database) PlayersRecord.txt
                ofstream writeFile("PlayersRecord.txt"); // Creates a new empty file named as "PlayersRecord.txt"
                writeFile.close();                       // closes the file "PlayersRecord.txt"
        }
}

void createDirectory()
{
        try
        {
                mkdir("PlayerDataBase");
        }
        catch (const std::exception &e)
        {
        }
}

void loadPrimaryIndex()
{
        int lineCount = 0;
        std::ifstream file("./PlayerDataBase/playerIdIndex.dat");
        if (file.is_open())
        {
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        int num = std::stoi(line);
                        playerIdIndexTree.insert(num);
                }
                file.close();
        }
}

void loadrunsScoredIndex()
{
        int lineCount = 0;
        std::ifstream file("./PlayerDataBase/playerRunsScoredIndex.dat");
        if (file.is_open())
        {
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        int num = std::stoi(line);
                        playerIdIndexTree.insert(num);
                }
                file.close();
        }
}

void loadCatchesIndex()
{
        int lineCount = 0;
        std::ifstream file("./PlayerDataBase/playerCatchesIndex.dat");
        if (file.is_open())
        {
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        int num = std::stoi(line);
                        playerIdIndexTree.insert(num);
                }
                file.close();
        }
}
void loadWicketsIndex()
{
        int lineCount = 0;
        std::ifstream file("./PlayerDataBase/playerWicketsIndex.dat");
        if (file.is_open())
        {
                std::string line;
                // just take the first 2 lines and ignore others
                while (std::getline(file, line))
                {
                        int num = std::stoi(line);
                        playerIdIndexTree.insert(num);
                }
                file.close();
        }
}

void initializeDB()
{
        createDirectory();
        loadPrimaryIndex();
}

void saveDatabase()
{
        playerIdIndexTree.save("./PlayerDataBase/playerIdIndex.dat");
        catchesIndexTree.save("./PlayerDataBase/playerCatchesIndex.dat");
        runsScoredIndexTree.save("./PlayerDataBase/playerRunsScoredIndex.dat");
        wicketsTakenIndexTree.save("./PlayerDataBase/playerWicketsIndex.dat");
}

int main()
{

        Player player;

        initializeDB();

        while (1)
        {
                int choice;
                cout << "\n\n=============== PLAYER Information System===================";
                cout << "\n1: Add a Player Record";
                cout << "\n2: Update A Player Record";
                cout << "\n3: Delete Player by PlayerId";
                cout << "\n4: Search Player using Player Id";
                cout << "\n5: Search Player using Player Name";
                cout << "\n6: List of player having runs scored more than and equal";
                cout << "\n7: List of player having wickets taken more than and equal";
                cout << "\n8: List of player having catched taken more tan and equal";
                cout << "\n9: Exit from Program";

                cout << "\n\nEnter your choice...!\n";
                cin >> choice;
                switch (choice)
                {

                // add a player
                case 1:
                        if (player.input())
                        {

                                int found;
                                btnode *node = playerIdIndexTree.search(player.getid(), playerIdIndexTree.getRoot(), &found);
                                if (node != NULL)
                                {
                                        cout << "Player id already Exists" << endl;
                                }
                                else
                                {
                                        // Takes input for the instance
                                        writeInFile(player); // 1: Writes the Input Record in File
                                        playerIdIndexTree.insert(player.getid());
                                        catchesIndexTree.insert(player.getCatchesTaken());
                                        wicketsTakenIndexTree.insert(player.getWicketsTaken());
                                        runsScoredIndexTree.insert(player.getRunsScored());
                                }
                        }
                        break;
                // update a record
                case 2:
                        updateRecord();
                        break;
                // delete a record
                case 3:
                        deleteInRecords();
                        break;

                // search records by id
                case 4:
                        searchRecords(1);
                        break;

                // search records by name
                case 5:
                        searchRecords(2);
                        break;

                // search runs scored
                case 6:
                        searchRunsScored();
                        break;

                // search wickets taken
                case 7:
                        searchWicketsTaken();
                        break;

                // search catched taken
                case 8:
                        searchCatchesTaken();
                        break;
                case 9:
                        cout << "Exiting from program...\n";
                        saveDatabase();
                        exit(0); // closes the program
                default:
                        cout << "Wrong Choice..! enter your choice again...\n";
                        break;

                } // end of switch;
        }         // end of while

} // end of main