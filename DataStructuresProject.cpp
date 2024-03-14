#include <iostream>
using namespace std;
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include<stack>
#include <unordered_map>
#include <vector>
class User;
class HashTable;
class MovieTree;
class Movie;
class map;
void mainpage(User &user, MovieTree &tree, HashTable &table, map &obj);
// goes to a specific point on the console based on x and y
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// changes text colour
void changecolor(int foreground, int background)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, foreground + background * 16);
}
// function for checking if xy|yz|zz has zz
bool DoesContain(string genre, string desired)
{
    string str1 = genre;
    string str2 = desired;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if (str1.find(str2) != string::npos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class Movie
{
public:
    string name;
    string id;
    string rating;
    string genre;
    string year;
    string dur;
    string d_name;
    string description;
    Movie *left;
    Movie *right;
    Movie *next; // this indicates that the movie has same rating
    Movie(string name, string rating, string genre, string year, string dur, string d_name, string description)
    {
        this->name = name;
        this->year = year;
        this->rating = rating;
        this->genre = genre;
        this->dur = dur;
        this->d_name = d_name;
        this->description = description;
        left = NULL;
        next = NULL;
        right = NULL;
    }
};
void display(Movie *movie, int size)
{
    int i = 12;
    int j = 40;
    gotoxy(i, j);
    cout << "MOVIE NAME: " << movie->name << endl;
    gotoxy(i + 1, j);
    cout << "MOVIE RATING: " << movie->rating << endl;
    gotoxy(i + 2, j);
    cout << "MOVIE GENRE: " << movie->genre;
    gotoxy(i + 3, j - 20);
    changecolor(0, 15);
    if (size == 2 || size==-1)
    {
        cout << "<--";
    }
    changecolor(15, 0);
    gotoxy(i + 3, j);
    cout << "Date: " << movie->year;
    if (size == 1 || size == 2)
    {
        gotoxy(i + 3, j + 50);
        changecolor(0, 15);
        cout << "-->" << endl;
        changecolor(15, 0);
    }
    gotoxy(i + 4, j);
    cout << "Duration: " << movie->dur;
    gotoxy(i + 5, j);
    cout << "Director Name: " << movie->d_name;
    gotoxy(i + 6, j);
    cout << "\tOverview\n"
         << movie->description;
}

class Node
{
public:
    Movie *movie;
    Node *next;
    Node *prev;
    bool addedw;
    bool addedl;
    Node(Movie *movie)
    {
        this->movie = movie;
        next = NULL;
        prev = NULL;
        addedw = false;
        addedl = false;
    }
};

bool checkname(string genre1, string genre2)
{
    transform(genre1.begin(), genre1.end(), genre1.begin(), ::tolower);
    transform(genre2.begin(), genre2.end(), genre2.begin(), ::tolower);
    if (genre1 == genre2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtTail(Movie *movie)
    {
        Node *temp = new Node(movie);
        if (tail == NULL)
        {
            tail = temp;
            head = temp;
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        }
    }
    void display(Node *iterator)
    {
        cout << "\n\n\n\n\n\n\t\t\t\t\t\tMOVIES TO WATCH";
        Node *temp = iterator;
        int i = 12;
        int j = 40;
        gotoxy(i, j);
        cout << "MOVIE NAME: " << iterator->movie->name << endl;
        gotoxy(i + 1, j);
        cout << "MOVIE RATING: " << iterator->movie->rating << endl;
        gotoxy(i + 2, j);
        cout << "MOVIE GENRE: " << iterator->movie->genre;
        gotoxy(i + 3, j - 20);
        changecolor(0, 15);
        cout << "<--";
        changecolor(15, 0);
        gotoxy(i + 3, j);
        cout << "Date: " << iterator->movie->year;
        gotoxy(i + 3, j + 50);
        changecolor(0, 15);
        cout << "-->" << endl;
        changecolor(15, 0);
        gotoxy(i + 4, j);
        cout << "Duration: " << iterator->movie->dur;
        gotoxy(i + 5, j);
        cout << "Director Name: " << iterator->movie->d_name;
        gotoxy(i + 6, j);
        cout << "\tOverview\n"
             << iterator->movie->description;
        gotoxy(25, 20);
        if (iterator->addedw == true)
        {
            changecolor(10, 0);
        }
        cout << "(a)add to watchlist";
        changecolor(15, 0);
        gotoxy(25, 70);
        if (iterator->addedl == true)
        {
            changecolor(10, 0);
        }
        cout << "(l)like";
        changecolor(15, 0);
    }
    bool Delete(string name)
    {
        Node *prev = head;
        Node *curr = head->next;
        if(curr==NULL)
		{
			if(checkname(prev->movie->name,name)==true)
			{
				head=NULL;
				delete prev;
				return 1;	
			}
		}
        while (checkname(curr->movie->name, name) == false || curr != head)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head)
        {
            return 0;
        }
        Node *forward = curr->next;
        prev->next = forward;
        forward->prev = prev;
        if (curr == tail)
        {
            tail = prev;
        }
        else if (curr == head)
        {
            head = forward;
        }
        curr->next = NULL;
        delete curr;
        return 1;
    }
    
};
class map
{
public:
    unordered_map<string, vector<Movie *>> collection;
    void Insert(string name, string rating, string genre, string year, string dur, string d_name, string description)
    {
        string arr[13] = {"comedy", "crime", "drama", "thriller", "war", "musical", "romance", "adventure", "noir", "sci-fi", "western", "fantasy", "mystery"};
        for (int i = 0; i < 13; i++)
        {
            if (DoesContain(genre, arr[i]) == true)
            {
            //    cout << "i was here" << endl;
                Movie *temp = new Movie(name, rating, genre, year, dur, d_name, description);
                collection[arr[i]].push_back(temp);
            }
        }
    }
    //used when user asks browse by genre
    void getit(string genre, stack<Movie *> &q)
    {
        transform(genre.begin(), genre.end(), genre.end(), ::tolower);
        if (collection.find(genre) != collection.end())
        {
            for (int i = 0; i < collection[genre].size(); i++)
            {
                q.push(collection[genre][i]);
            }
        }
        else
        {
            cout << "Sorry such a genre doesnt exist" << endl;
        }
    }

    //called recbypref
    void add(string genre,List &random)
    {
        transform(genre.begin(), genre.end(), genre.end(), ::tolower);
         if (collection.find(genre) != collection.end())
        {
            for (int i = 0; i < collection[genre].size(); i++)
            {
               random.InsertAtTail(collection[genre][i]);
            }
        }
    }
    //The recommendaton list will be made with respect to genres chosen
    void recbypref(vector<string> &Genres,List &random)
    {
        for(int i=0;i<Genres.size();i++)
        {
            add(Genres[i],random);
        }
    }
    //The recommendation list will be made with respect to movies liked
    void recbypref(List list,List &random)
    {
        Node *temp=list.head;
        while(temp->next!=list.head)
        {
            add(temp->movie->genre,random);
            temp=temp->next;
        }
    }
};
class User
{
public:
    string id;
    string pass;
    bool status;
    vector<string> Genres; // the genres that the user likes
    List WatchList;        // a linked list of the movies user wants to watch
    List recommender;      // displayed on the front page
    List liked;            // a linked list of the movies user likes
    User(string id, string pass)
    {
        this->id = id;
        this->pass = id;
        status = false;
    }
    User()
    {
        id = "";
        pass = "";
        status = false;
    }
    void makemember()
    {
        status = true;
    }
    void watchlist()
    {
        system("cls");
        if (status == false)
        {
            cout << "\n\n\n\n\n\n\t\t\t\t\tSorry you have not signed in!" << endl
                 << endl;
            cout << "\t\t\tSign in or create a new account and get a chance to try new features" << endl;
            cout << "Press any key to go back..." << endl;
            getch();
        }
        else
        {
            Node *temp = WatchList.head;
            if (temp == NULL)
            {
                cout << "\n\n\n\n\n\n\t\t\t\t\tYou have not added any movies yet!" << endl;
                cout << "Press any key to back...";
                getch();
                return;
            }
            do{
                cout << temp->movie->name << endl;
                temp = temp->next;
            }while(temp!=WatchList.head);
            system("pause");
        }
    }
    void userdetails()
    {
        system("cls");
        cout << "\n\n\n\n";
        int length = Genres.size();
        cout << "Name:" << id << endl;
        cout << "Password" << pass << endl;
        cout << "Favourites Genres(" << length << "):";
        if (length == 0)
        {
            cout << "Not selected" << endl;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                cout << "\n\t\t\t" << Genres[i];
            }
        }

        cout << "\nLiked movies" << endl;
        Node *temp = liked.head;
        int i=1;
        if (temp == NULL)
        {
            cout << "Liked none" << endl;
        }
        else
        {
            do
            {
                cout <<"i"<< temp->movie->name << endl;
                temp = temp->next;
                i++;
            } while (temp != liked.head); // since doubly linked list
        }
        i=1;
        cout << "Watchlist" << endl;
        temp = WatchList.head;
        if (temp == NULL)
        {
            cout << "None included yet" << endl;
        }
        else
        {
            do
            {
                cout <<"i"<< temp->movie->name << endl;
                temp = temp->next;
            } while (temp != WatchList.head); // since doubly linked list
        }
        cout << "\n\n\t\t(b)go back\t\t(u)unlike movie\t\t(w)remove from watchlist" << endl;
        while (1)
        {
            bool deleted = false;
            char choice = getch();
            string name;
            switch (choice)
            {
            case 'b':
            {
                return;
            }
            case 'u':
            {
            	if(liked.head==NULL)
				{
					break;
				}
                cout << "Enter movie name" << endl;
                cin.ignore();
                getline(cin, name);
                bool deleted = liked.Delete(name);
                if (deleted == false)
                {
                    cout << "You have not liked this movie" << endl;
                }
                system("pause");
                break;
            }
            case 'w':
            {
                cout << "Enter movie name" << endl;
                cin.ignore();
                getline(cin, name);
                bool deleted = WatchList.Delete(name);
                if (deleted == false)
                {
                    cout << "Movie not found in watchlist" << endl;
                }
                system("pause");
                return;
                break;
            }
            default:
            {
                break;
            }
            break;
            }
        }

        system("pause");
    }
};

void header(User &obj)
{
    changecolor(0, 6);
    cout << "IMDb";
    changecolor(15, 0);
    cout << "\t";
    changecolor(8, 15);
    cout << "(b)Browse IMDb                                              ";
    changecolor(0, 15);
    cout << "|v|";
    changecolor(15, 0);
    cout << "\t+Watchlist(w)";
    // changecolor(15,8);
    // cout<<"1. Search by Movie ID                                          ";
    changecolor(15, 0);
    if (obj.status == true)
    {
        cout << "\t(u)User Details";
    }
    else
    {
        cout << "\t(s)Sign in";
    }
    cout << "\t(e)end";
}

void Detail(stack<Movie*>& q, User user, stack<Movie*>& s)
{
    bool left;
    system("cls");
    header(user);
    int size;
    while (!q.empty() || !s.empty())
    {
        cout << "\n\n\n<- (b)back" << endl;
        left = false;
        Movie* movie;

        if (!s.empty())
        {
            movie = s.top();
        }
        else if (!q.empty())
        {
            movie = q.top();
        }
        if(q.size()>1 && s.size()>0)
        {
            size=2;//both arrows;=
        }
        if(q.size()==1 && s.size()==0)
        {
            size=0;//no arrow;
        }
        if(q.size()>1 && s.size()==0)
        {
            size=1;//only forward
        }
        if(q.size()==1 && s.size()>0)
        {
            size=-1;//back arrow
        }
        display(movie, size);

        char choice = _getch();
        if (choice == 'b')
        {
            break;
        }
        else if (choice == 77)  // Right arrow key
        {
            if (!q.empty())
            {
                s.push(q.top());
                q.pop();
            }
        }
        else if (choice == 75)  // Left arrow key
        {
            if (!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
        }

        system("cls");
        header(user);
    }

    while (!q.empty())
    {
        q.pop();
    }

    while (!s.empty())
    {
        s.pop();
    }
}

// A BST based on movie name
class MovieTree
{
public:
    Movie *root;
    stack<Movie *> random;
    stack<Movie *> s;
    MovieTree()
    {
        root = NULL;
    }

    void insert(string name, string rating, string genre, string year, string dur, string d_name, string description, Movie *&root)
    {

        if (root == NULL)
        {
            Movie *temp = new Movie(name, rating, genre, year, dur, d_name, description);
            root = temp;
        }
        else if (name < root->name) // based on ascii value
        {
            insert(name, rating, genre, year, dur, d_name, description, root->left);
        }
        else if (name > root->name)
        {
            insert(name, rating, genre, year, dur, d_name, description, root->right);
        }
    }

    void topratedmovies(Movie *root, stack<Movie *> &q)
    {

        if (root == 0)
        {
            return;
        }
        else if (root->rating == "4" || root->rating == "5" || root->rating == "4.5")
        {
            q.push(root);
        }
        topratedmovies(root->left, q);
        topratedmovies(root->right, q);
    }
    void inorder(Movie *r, stack<Movie *> &q)
    {
        if (r == 0)
        {
            return;
        }
        inorder(r->left, q);
        q.push(r);
        inorder(r->right, q);
    }

    // This function displays all the movies that are present in the BST.
    void display(stack<Movie *> &q)
    {
        cout << "\n\t\t\tDisplay All Data: " << endl;
        inorder(root, q);
    }
    bool BrowseByRating(string rating, Movie *&root, stack<Movie *> &q)
    {
        if (root == NULL)
        {
            return false;
        }
        else if ((root->rating == rating))
        {
            q.push(root);
            return true;
        }
        bool foundleft = BrowseByRating(rating, root->left, q);
        bool foundright = BrowseByRating(rating, root->right, q);

        if (foundleft == true || foundright == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // not very efficient
    // maps lagakey dekho

    void browsebyGenre(string genre, Movie *&root, stack<Movie *> &q)
    {
        if (root == NULL)
        {
            return;
        }
        browsebyGenre(genre, root->left, q);
        if (DoesContain(root->genre, genre) == true)
        {
            q.push(root);
        }

        browsebyGenre(genre, root->right, q);
    }

    bool SearchByName(string name, Movie *&root, stack<Movie *> &q)
    {
        bool found = false;
        if (root == NULL)
        {
            return false;
        }
        if (name == root->name)
        {
            q.push(root);
            found = true;
            return found;
        }
        else if (name < root->name)
        {
            found = SearchByName(name, root->left, q);
        }
        else if (name > root->name)
        {
            found = SearchByName(name, root->right, q);
        }
        return found;
    }

    void randomiser(Movie *&root, List &obj)
    {
        if (root == NULL)
        {
            return;
        }
        else if (root->rating == "4" || root->rating == "5" || root->rating == "4.5")
        {
            // cout<<root->rating<<endl;
            obj.InsertAtTail(root);
        }
        randomiser(root->left, obj);
        randomiser(root->right, obj);
    }
    /*void traverse(Movie *&root,string genre,List &list)
    {

    }
    //called when no user.Genres is empty
    void randbypref(Movie *&root, List &random,List &list)//random is the linkedlist of main page
    {
        Node *temp=list.head->next;
        while(temp!=list.head)
        {
            traverse(root,temp->movie->genre);
            temp=temp->next;
        }
        traverse(root,temp->movie->genre);
    }
    void randbypref(Movie *&root,Vector<string>Genre,List &list)//random is the linkedlist of main page
    {
        Node *temp=list.head->next;
        for(int i=0;i<Genre.size();i++)
        {
            traverse(root,);
        }
    }*/
    // x----------------x--------------x
};
// this admin will add/change the latest top trending movies(optional)
// x-----------------x----------------x

void changecolor(int index, int *arr)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (arr[index] == 1)
    {
        SetConsoleTextAttribute(hConsole, 2);
    }
    else if (index == -1 || arr[index] != 1)
    {
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Personalise(User &obj, MovieTree &tree, HashTable &table, map &obj1)
{
    int count = 0;
    int choice;
    int arr[6] = {-1, -1, -1, -1, -1, -1};

    while (count != 6)
    {
        system("cls");
        cout << "To get you going choose your preferred genres" << endl;
        for (int i = 0; i < 6; i++)
        {
            changecolor(i, arr);
            if (i == 0)
            {
                cout << "1.Crime";
            }
            else if (i == 1)
            {
                cout << "\t\t2.Thriller";
            }
            else if (i == 2)
            {
                cout << "\t\t3.Mystery" << endl
                     << endl;
            }
            else if (i == 3)
            {
                cout << "4.Comedy";
            }
            else if (i == 4)
            {
                cout << "\t5.noir";
            }
            else if (i == 5)
            {
                cout << "\t\t6.Fantasy" << endl;
            }
        }
        changecolor(-1, arr);
        if (count + 1 == 1)
        {
            cout << "\n\t\t\t\t\t(7)skip";
        }
        else
        {
            cout << "\n\t\t\t\t\t(7)next";
        }
        choice = getch();
        if (choice == '7')
        {
            break;
        }
        if (choice >= '1' && choice <= '6')
        {
            if (arr[choice - '0' - 1] == -1)
            {
                if (choice == '1')
                {
                    obj.Genres.push_back("crime");
                }
                else if (choice == '2')
                {
                    obj.Genres.push_back("thriller");
                }
                else if (choice == '3')
                {
                    obj.Genres.push_back("mystery");
                }
                else if (choice == '4')
                {
                    obj.Genres.push_back("comedy");
                }
                else if (choice == '5')
                {
                    obj.Genres.push_back("noir");
                }
                else if (choice == '6')
                {
                    obj.Genres.push_back("fantasy");
                }
                arr[choice - '0' - 1] = 1;
                count++;
            }
        }
    }
    system("cls");
    mainpage(obj, tree, table, obj1);
    // browse();
}

void Signup(MovieTree &tree, HashTable &table, map &obj1)
{
    string username1, username2, password;
    bool found = false;
    ofstream writer("database.txt", ios::binary | ios::app);
    ifstream reader("database.txt", ios::binary | ios::in);
    while (1) // if username is  already taken it would revisit
    {
        int i;
        system("cls");
        cout << "\t\tEnter username: ";
        cin >> username1;
        while (getline(reader, username2))
        {
            if (username1 == username2)
            {
                cout << endl
                     << endl
                     << "This username is already taken! Select a unique username for yourself" << endl;
                reader.seekg(0, ios::beg);
                cout << endl
                     << "press any key to continue...." << endl;
                getch();
                break;
            }
        }
        if (username1 != username2)
        {
            break;
        }
    }
    reader.close();
    cout << "\t\tENter password: ";
    cin >> password;
    cout << endl
         << endl
         << "\tAccount created successfully!" << endl;
    writer << username1 << endl;
    writer << password << endl;
    writer.close();
    User obj(username1, password);
    obj.makemember(); // have access to more features
    Personalise(obj, tree, table, obj1);
    // now take initial info 4 favourites/genres interested in etc
}

int stringtoint(string data)
{
    int value = 0;
    int length = data.length();
    for (int i = 0; i < length; i++)
    {
        value = value * 10 + (data[i] - '0');
    }
    return value;
}
int getyear(string data)
{
    int length = data.length();
    int count = 0;
    int i = 0;
    while (count != 2 && i < length)
    {
        if (data[i] == '/')
        {
            count++;
        }
        i++;
    }
    string year = data.substr(i, length - i);
    int intyear = stringtoint(year);
    return intyear;
}
int hashfunc(string data, int size)
{
    int year = getyear(data);
    return year % size;
}
class HashTable
{
private:
    Movie **arr;
    int size;

public:
    HashTable(int size)
    {
        this->size = size;
        arr = new Movie *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }
    void Insert(string name, string rating, string genre, string year, string dur, string d_name, string description)
    {
        Movie *temp = new Movie(name, rating, genre, year, dur, d_name, description);
        int index = hashfunc(year, size);
        Movie *head = arr[index];
        if (head == NULL)
        {
            // cout<<"yahan pohncha?"<<endl;
            arr[index] = temp;
        }
        else
        {
            temp->next = head;
            arr[index] = temp;
        }
    }
    void browsebyYear(string year, stack<Movie *> &q)
    {
        int intyear = stringtoint(year);
        if (intyear < 2000 && intyear > 2020)
        {
            cout << "Oops! Sorry we donot have movies from that age of time" << endl;
        }
        int index = hashfunc(year, size);
        Movie *temp = arr[index];
        while (temp != NULL)
        {
            q.push(temp);
            temp = temp->next;
        }
    }
    void randbypref()
    {

    }
     
};
bool checkvalidity(string date)
{
    int length = date.length();
    int slash = 0;
    for (int i = 0; i < length; i++)
    {
        if (date[i] == '/')
        {
            slash++;
        }
        if ((date[i] >= '0' && date[i] <= '9') || date[i] == '/')
        {
            ;
        }
        else
        {
            return 0;
        }
    }
    if (slash != 2)
    {
        return 0;
    }
    return 1;
}
void Browse(MovieTree &tree, HashTable &table, User &user, map &obj)
{
    system("cls");
    header(user);
    cout << "\t\t\t\t\t1. Search by Movie Name.\n"
         << endl;
    cout << "\t\t\t\t\t2. Search by Movie Release Date.\n"
         << endl;
    cout << "\t\t\t\t\t3. Search by Movie Genre.\n"
         << endl;
    cout << "\t\t\t\t\t4. Search Top Rated Movies.\n"
         << endl;
    cout << "\t\t\t\t\t5. Search by your Prefered Rating.\n"
         << endl;
    cout << "\t\t\t\t\t6. Display all Movies.\n"
         << endl;
    char opt;
    cout << "\t\t\t\t\tEnter any option number: ";
    opt = _getch();
    cout << "\n\t\t\t\t\t";
    // system("CLS");
    string name, rating, genres, date, dur, imdb, d_name, overview, rate;
    stack<Movie *> q;
    stack<Movie *>s;
	switch (opt)
    {
    case '1':
    {
        cout << "\n\n\n\n\t\t\t\t\tEnter the Movie Name: ";
        getline(cin, name);
        cout << "\n\t\t\t\t\t";
        system("CLS");
        bool found = tree.SearchByName(name, tree.root, q);
        if (!found)
        {
            cout << "\n\n\n\n\t\tUnable to find movie,try typing something else" << endl;
            system("pause");
        }
        else
        {
            Detail(q, user,s);
        }
        break;
    }
    case '2':
    {
        cout << "\n\n\n\n\t\t\t\t\tEnter the Movie Release Date (DD/MM/YY): ";
        while (1)
        {
            getchar();
            getline(cin, date);
            cout << "\n\t\t\t\t\t";
            bool valid = checkvalidity(date);
            if (!valid)
            {
                cout << "Enter valid date!" << endl;
            }
            else
            {
                break;
            }
        }
        table.browsebyYear(date, q);
        Detail(q, user,s);
        break;
    }
    case '3':
    {
        cout << "\n\n\n\n\t\t\t\t\tEnter the Movie Genre: ";
        cin >> genres;
        cout << "\n\t\t\t\t\t";
        obj.getit(genres, q);
        Detail(q, user,s);

        break;
    }
    case '4':
    {
        tree.topratedmovies(tree.root, q);
        Detail(q, user,s);
        return;
    }
    case '5':
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\tEnter your Prefered Rating in Number(1-5): ";
        getline(cin, rating);
        bool found = tree.BrowseByRating(rating, tree.root, q);
        if (!found)
        {
            cout << "Sorry we donot have a movie with this rating" << endl;
        }
        Detail(q, user,s);

        break;
    }
    case '6':
    {
        cout << "\n\n\n\n\t\t\t\t\tList of all Movies: " << endl;
        tree.display(q);
        Detail(q, user,s);
        system("CLS");
        break;
    }
    }
}
// x-------------------x-------------------x
void mainpage(User &user, MovieTree &tree, HashTable &table, map &obj)
{
    system("cls");
    char choice;
    header(user);
    List random;
    if (user.Genres.size() == 0 && user.liked.head == NULL)//user hasnt added any preference
    {
        tree.randomiser(tree.root, random);
    }
    else if (user.liked.head != NULL)//user liked some movies
    {
        obj.recbypref(user.liked,random);
    }
    else if(user.Genres.size()!=0)//user added genres
    {
        obj.recbypref(user.Genres,random);
    }
    Node *temp = random.head;
    random.display(temp);
    while (1)
    {
        choice = _getch();
        switch (choice)
        {
        case 'b':
        {
            Browse(tree, table, user, obj);
            break;
        }
        case 's':
        {
            if (user.status == false)
            {
                return;
            }
            break;
        }
        case 'w':
        {
            user.watchlist();
            system("cls");
            break;
        }
        case 'u':
        {
            if (user.status == true)
            {
                user.userdetails();
            }
            break;
        }

        case 'e':
        {
            // writing user details in file
            // leave(obj);
            return;
            break;
        }
        case 77:
        {
            system("cls");
            header(user);
            temp = temp->prev;
            random.display(temp->prev);
            break;
        }
        case 75:
        {
            system("cls");
            header(user);
            temp = temp->next;
            random.display(temp->next);
            break;
        }
        case 'l':
        {

            if (user.status != false && temp->addedl == false)
            {
                user.liked.InsertAtTail(temp->movie);
                temp->addedl = true;
            }
            else if (temp->addedl == true)
            {
                break;
            }
            else
            {
                gotoxy(26, 30);
                cout << "Please sign in to access this feature" << endl;
                system("pause");
            }
            break;
        }
        case 'a':
        {
            if (user.status != false && temp->addedw == false)
            {
                user.WatchList.InsertAtTail(temp->movie);
                temp->addedw = true;
            }
            else if (temp->addedw == true)
            {
                break;
            }
            else
            {
                gotoxy(26, 30);
                cout << "Please sign in to access this feature" << endl;
                system("pause");
            }
            break;
        }
        default:
        {
            break;
        }
        }
        system("cls");
        header(user);
        random.display(temp);
    }
}

void Home()
{
    char choice;
    HashTable table(21); // movie record of 21 years
    MovieTree tree;      // tree based on ascii values of names
    map obj;
    ifstream ip("movies_dataset.csv");
    ifstream ic("data1.csv");
    ifstream iz("overview.csv");
    if (!ip.is_open() || !ic.is_open() || !iz.is_open())
    {
        cout << "error while opening file" << endl;
    }
    string name, rating, genres, date, dur, imdb, d_name, overview;
    vector<string> row;
    string line1, line2, line3, word;
    // to getrid of headings from the csv file
    getline(ic, line1);
    getline(ip, line2);
    getline(iz, line3);
    int count = 0;
    while (getline(ic, line1) && getline(ip, line2) && getline(iz, line3) && count < 20)
    {
        overview = line3;
        row.clear();
        stringstream s(line1);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        date = row[0];
        // cout << date << endl;
        dur = row[1];
        // cout << dur << endl;
        d_name = row[2];
        // cout << d_name << endl;
        row.clear();
        stringstream a(line2);
        while (getline(a, word, ','))
        {
            row.push_back(word);
        }
        name = row[0];
        // cout << name << endl;
        rating = row[1];
        // cout << rating << endl;
        genres = row[2];
        // cout << genres << endl;
        tree.insert(name, rating, genres, date, dur, d_name, overview, tree.root);
        table.Insert(name, rating, genres, date, dur, d_name, overview);
        obj.Insert(name, rating, genres, date, dur, d_name, overview);
        count++;
    }
    // cout << c;
    ip.close();
    ic.close();
    iz.close();
    // table.print();
    // getchar();
    // tree.randmaker();
    while (1)
    {
        changecolor(0, 6);
        cout << "IMDb";
        changecolor(15, 0);
        cout << "\n\n\n\t\t\t\tWelcome to letterboxd/rotten tomatoes/IMDb/metacritic" << endl;
        cout << "\t\t\t\t\t\tMovies,Movies and Movies" << endl;
        cout << endl
             << "\n\n\t\t\t\t\t\t(1)Sigup" << endl
             << "\n\n\t\t\t\t\t\t(2)Visit as guest" << endl;
        choice = getch();
        if (choice == '1')
        {
            Signup(tree, table, obj);
            return;
        }
        else if (choice == '2')
        {
            User guest;
            mainpage(guest, tree, table, obj);
            // no favourites/reviews/likes allowed only browsing
        }
        system("cls");
    }
}
int main()
{
    Home();
    // cout<<getyear("22/12/2004");
    return 0;
}