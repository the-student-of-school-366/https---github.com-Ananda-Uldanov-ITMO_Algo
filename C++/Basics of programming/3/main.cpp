#include "func.cpp"
int main()
{
    cout << "\n cin x, y, length, angle\n";
    int x;
    int y;
    int length;
    int angle;
    //cin >> x >> y >> length >> angle;
    Square square(x, y, length, angle);
    cout << "\n11. AddVector.\n12. Equality.\n13. Increase.\n14.\n16. Show. \n7. Stop.\n";
    cout << "\n21. AddSet.\n22. Equality.\n23. AddNumber.\n24. DeleteNumber. \n26. Show. \n7. Stop.\n";
    int choice;
    char choose;
    bool exit = false;
    Array mas;
    while (cin >> choice && !exit)
    {
        if (choice == 11)
        {
            int x1;
            int x2;
            cout << "\n(AddVector) Enter x1, x2:";
            cin >> x1 >> x2;
            square.AddVector(x1, x2);
        }
        else if (choice == 12)
        {
            int x1, y1, length1, angle1;
            cout << "\n cin x1, y1, length1, angle1";
            cin >> x1 >> y1 >> length1 >> angle1;
            Square square1(x1, y1, length1, angle1);
            if (square == square1)
            {
                cout << "\n Squares are equal";
            }
            else if (square > square1)
            {
                cout << "\n First is bigger";
            }
            else
            {
                cout << "\n Second is bigger";
            }
        }
        else if (choice == 13)
        {
            int k;
            cin >> k;
            square.increase(k);
        }
        else if (choice == 16)
        {
            square.Show();
        }

        if (choice == 21)
        {
            int n;
            int x;
            cout << "\n(AddVector) Enter number of elements, elements:";
            cin >> n;
            Array mas1;
            for (int i = 0; i < n; i++)
            {
                cin >> x;
                mas1 += x;
            }
            mas=mas + mas1;

        }
        else if (choice == 22)
        {
            int k;
            cout << "\n cin number of elements";
            cin >> k;
            cout << "\n cin elements";
            Array mas1;
            for(int i=0;i<k;i++)
            {
                int tmp;
                cin>>tmp;
                mas1+=tmp;
            }
            if (mas == mas1)
            {
                cout << "\n They are equal\n";
            }
            else
            {
                cout << "\n They are NOT equal\n";
            }
        }
        else if (choice == 23)
        {
            int k;
            cin >> k;
            mas += k;
        }
        else if (choice == 24)
        {
            int k;
            cin >> k;
            mas -= k;
        }
        else if (choice == 26)
        {
            mas.Show();
        }
    }
}