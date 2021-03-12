// Lesson 08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Lesson 08.h"
#include <random>
#include<algorithm>
#include<functional>
#define CHECK_DOT(x, size) ((x) >= 0 && (x) < (size))
#define POINT_ITEM(a, r, c) (*((*(a + r)) + c))
using namespace std;

//conditions
enum PLAYER{HUMAN='X', AI='0', EMPTY='_'};

typedef struct 
{
    int szX;
    int szY;
    PLAYER** map;
    int towin;
}Field;

int getX, getY, numW;

//functions

int checknumber(const string &txt_string)
{
    while (true)
    {
        int num;
        cout << txt_string << '\n';
        cin >> num;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Please, enter number: \n";
        }
        else
        {
            return num;
        }
    }
}

int startGame()
{
    char GT;
    cout << "Welcome PLAYER \n Do you want Play \n Standart Game 3x3 (s)\n Modified Game AxB (m)" << endl;
    ret:
    cin >> GT;
    switch (GT)
    {case 's':
        getX = 3;
        getY = 3;
        numW = 3;
        break;
    case 'm':
        /*cout << "Enter the number of rows and columns: \n";
        cin >> getX >> getY;
        cout << "Enter the length of win line \n";
        cin >> numW;*/
        getX = checknumber("Enter the number of rows: \n");
        getY = checknumber("Enter the number of columns: \n");
        numW = checknumber("Enter the length of win line \n");

        break;
    default:
        cout << "Enter S for Standart Game or M for Modified Game" << endl;
        goto ret;
        break;
    }
    return getX;
    return getY;
    return numW;
}

void setval(PLAYER** map, int x, int y, PLAYER state)
{
    POINT_ITEM(map, x, y) = state;
};

char getval(PLAYER** map, const int x, const int y)
{
    return POINT_ITEM (map, x, y);
};

int isvalid(Field &field, int x, int y)
{
    return CHECK_DOT(x, field.szX) && CHECK_DOT(y,field.szY);
} 

int isempty(Field& field, int x, int y)
{
    return getval(field.map, y, x) == EMPTY;
} 

int check_line(Field& field, int y, int x, int vx, int vy, int len, PLAYER c)
{
    const int endx = x + (len - 1) * vx;
    const int endy = y + (len - 1) * vy;
    if (!isvalid(field, endx, endy))
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (getval(field.map, (y + i * vy), (x + i * vx)) != c)
            return 0;
    }
    return 1;
}; 

int check_win(Field& field, PLAYER player)
{
    for (int y = 0; y < field.szX; y++)
    {
        for (int x = 0; x < field.szY; x++)
        {
            if (check_line(field, y, x, 1, 0, field.towin, player)) // по горизонтали
                return 1;
            if (check_line(field, x, y, 0, 1, field.towin, player)) // по вертикали
                return 1;
            if (check_line(field, x, y, 1, 1, field.towin, player)) // по диагонали
                return 1;
            if (check_line(field, x, y, 1, -1, field.towin, player)) // по диагонали
                return 1;
        }
    }
    return 0;
}

int check_draw(Field& field)
{
    for (int y = 0; y < field.szY; y++)
    {
        for (int x = 0; y < field.szX; x++)
        {
            if (isempty(field, x, y))
                return 0;
        }
        
    }
    return 1;
}

int check_game(Field& field, PLAYER p, const string& win_string)
{
    if (check_win(field, p))
    {
        cout << win_string << '\n';
        return 1;
    }
    else if (check_draw(field))
    {
        cout << "Draw" << '\n';
        return 1;
    }
    return 0;
};


   //start game
void init(Field& field)
{
    field.towin = numW;
    field.szX = getX;
    field.szY = getY;
    field.map = (PLAYER**) calloc(sizeof(PLAYER*), field.szY);
    for (int i = 0; i < field.szY; ++i)
    {
        *(field.map+i) = (PLAYER*) calloc(sizeof(PLAYER),field.szX);
        for (int j = 0; j < field.szX; ++j)
        {
            setval(field.map, i, j, EMPTY);
        }
    }
}

void print(Field& field)
{
    system("cls");
    cout << "--------------\n";
    for (int i = 0; i < field.szY; ++i)
    {
        cout << '|';
        for (int j = 0; j < field.szX; ++j)
        {
            char get = getval(field.map, i, j);
            cout << get << '|';
        }
        cout << '\n';   
    }
}

void human_move(Field &field)
{
    int x, y;
    do
    {
        cout << "Enter collum and row: ";
        cin >> x >> y;
        x--;
        y--;
    } while (!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, y, x, HUMAN);
}

int aiwincheck(Field& field)
{
    for (int i = 0; i < field.szY; i++)
    {
        for (int j = 0; j < field.szX; j++)
        {
            if (isempty(field, j, i))
            {
                setval(field.map, i, j, AI);
                if (check_win(field, AI))
                    return 1;
                setval(field.map, i, j, EMPTY);
            }
        }
    }
    return 0;
}

int humanwincheck(Field& field)
{
    for (int i = 0; i < field.szY; i++)
    {
        for (int j = 0; j < field.szX; j++)
        {
            if (isempty(field, j, i))
            {
                setval(field.map, i, j, HUMAN);
                if (check_win(field, HUMAN))
                {
                    setval(field.map, i, j, AI);
                    return 1;
                }
                setval(field.map, i, j, EMPTY);
            }
        }
    }
    return 0;
}

void ai_move(Field& field)
{
    int x, y;
    random_device rd;
    mt19937 rnd(rd());
    uniform_real_distribution<double> dist(0, 3);
    
    if (aiwincheck(field) == 1)
    {
        aiwincheck(field);
    }
    if (humanwincheck(field) == 1)
    {
        humanwincheck(field);
    }
    else {
        do
        {
            x = dist(rnd);
            y = dist(rnd);
        } while (!isempty(field, x, y));
        setval(field.map, y, x, AI);
    }
}
        
 void tictactoe()
{
    Field field;
    while (true)
    {
        init(field);
        print(field);
        while (true)
        {
            human_move(field);
            print(field);
            if (check_game(field, HUMAN, "Human win!")) break;

            ai_move(field);
            print(field);
            if (check_game(field, AI, "AI win!")) break;
        }
        string answer;
        cout << "Play again? \n Yes: y No: n \n";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        if (answer.find('y') !=0)
            break;
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    startGame ();
    tictactoe ();
   
}

