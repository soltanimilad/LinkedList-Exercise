#include "LinkedList.cpp"
void JusephusGame()
{
    system("cls");
    system("COLOR 04");
    int NumberOfPlayers, Steps, StartingPoint;
    // create a circular list for the players
    CircularLinkedList *DeathGameList = new CircularLinkedList();
    std::cout << "\n\n\n\n\t\tPlease enter the number of players:\tNumber of Player , Steps , StartigPoint" << std::endl;
    std::cin >> NumberOfPlayers;
    std::cin >> Steps;
    std::cin >> StartingPoint;
    // Input Verification
    if (NumberOfPlayers < 2 || Steps < 1 || StartingPoint < 2 || StartingPoint > NumberOfPlayers)
    {
        std::cout << "Try Again\n";
        JusephusGame();
    }
    // give every player a number
    for (int i = 1; i <= NumberOfPlayers; i++)
    {
        DeathGameList->Insert(i);
    }
    // create a node pointer to move it along the the players and assign it to the first player
    Node *temp = new Node;
    temp = DeathGameList->getFirst();
    // Show All players
    std::cout << "Players:\n";
    DeathGameList->ShowAll();
    // move the pointer to the starting player
    for (int i = 2; i < StartingPoint; i++)
    {
        temp = temp->Next;
    }
    // eliminate the starting point player outside the loop
    std::cout << "Player Number " << temp->Next->Value << " eliminated" << std::endl;
    DeathGameList->DeleteAfter(temp);
    NumberOfPlayers--;
    std::cout << "Players:\n";
    DeathGameList->ShowAll();
    // loop to eliminate and move the pointer as the steps
    while (NumberOfPlayers > 1)
    {
        for (int i = 1; i < Steps; i++)
        {
            temp = temp->Next;
        }
        std::cout << "Player Number " << temp->Next->Value << " eliminated" << std::endl;
        DeathGameList->DeleteAfter(temp); // delete the node after the current node
        NumberOfPlayers--;
        std::cout << "Players:\n";
        DeathGameList->ShowAll();
    }
    int choice;
    std::cout << "\n\n\t\t  1-Main Menu  \t\t\t  2-Try Again\n";
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        JusephusGame();
    default:
        break;
    }
}
void printArray(int **a, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            std::cout << "\t" << a[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void SymmetricalArrayChecker()
{
    system("cls");
    system("COLOR F1");
    int n;
    std::cout << "\n\n\n\n\t\tEnter The Number Of Rows And Columns(n*n):\n";
    std::cin >> n;
    // declare a dynamic 2d array for our matrix
    int **array = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(n * sizeof(int));
    }
    // assign values to matrix
    int value;
    printArray(array, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            system("cls");
            printArray(array, n); // to show where each element sit
            std::cin >> value;
            array[i][j] = value;
        }
    }
    system("cls");
    printArray(array, n);
    // check if the matrix is symmetrical
    bool IsSymmetrical = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (array[i][j] != array[j][i])
            {
                IsSymmetrical = false;
            }
        }
    }
    if (IsSymmetrical)
    {
        std::cout << "\n\n\t\tThe Matrix Is Symmetrical\n";
    }
    else
    {
        std::cout << "\n\n\t\tThe Matrix Is Not Symmetrical\n";
    }
    std::cout
        << "\n\n\t\t  1-Main Menu  \t\t\t  2-Try Again\n";
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        SymmetricalArrayChecker();
    default:
        break;
    }
}
// merging two list function
Node *MergeTwoList(Node *x, Node *y)
{
    Node *result = nullptr;
    if (x == nullptr)
        return y;
    if (y == nullptr)
        return x;
    if (x->Value <= y->Value)
    {
        result = x;
        result->Next = MergeTwoList(x->Next, y);
    }
    else
    {
        result = y;
        result->Next = MergeTwoList(x, y->Next);
    }
    return result;
}
void InsertionSortOnTwoLinkedList()
{
    system("cls");
    system("COLOR 27");
    // declare two list
    SingularLinkedList *List_1 = new SingularLinkedList();
    SingularLinkedList *List_2 = new SingularLinkedList();
    // give it values which is sorted(each input is bigger than the previous one)
    int temp = -1;
    int value;
    while (std::cin >> value)
    {
        if (value > temp)
        {
            List_1->InsertLast(value);
            temp = value;
            system("cls");
            List_1->ShowAll();
            continue;
        }
        else if (value == -1)
        {
            break;
        }
        else
        {
            system("cls");
            List_1->ShowAll();
            continue;
        }
    }
    system("cls");
    List_1->ShowAll();
    std::cout << "\n";
    temp = -1;
    while (std::cin >> value)
    {
        if (value > temp)
        {
            List_2->InsertLast(value);
            temp = value;
            system("cls");
            List_2->ShowAll();
            continue;
        }
        else if (value == -1)
        {
            break;
        }
        else
        {
            system("cls");
            List_2->ShowAll();
            continue;
        }
    }
    // print both list
    system("cls");
    List_1->ShowAll();
    std::cout << "\n";
    List_2->ShowAll();
    // merge two lists
    Node *result = MergeTwoList(List_1->getFirst(), List_2->getFirst());
    SingularLinkedList *res = new SingularLinkedList(result);
    std::cout << "\n";
    res->ShowAll();
    std::cout << "\n\n\t\t  1-Main Menu  \t\t\t  2-Try Again\n";
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        InsertionSortOnTwoLinkedList();
    default:
        break;
    }
}
void ValueDoublerInALinkedList()
{
    system("cls");
    system("COLOR 80");
    SingularLinkedList *List_1 = new SingularLinkedList();
    // create the list from user input
    int value;
    while (std::cin >> value)
    {
        if (value == -1)
        {
            break;
        }
        List_1->InsertLast(value);
        system("cls");
        List_1->ShowAll();
    }
    system("cls");
    List_1->ShowAll();
    std::cout << "\n\n\t\t Which Value you want to double in the list:\n";
    int n;
    std::cin >> n;
    Node *temp = new Node; // pointer to iterate through the list
    Node *t = new Node;
    temp = List_1->getFirst();
    t = List_1->getFirst(); // second pointer(needed to avoid infinite loop)
    // while loop to move along the list until we reach the end
    while (t != nullptr)
    {
        t = temp->Next; // store the next node
        if (temp->Value == n)
        {
            List_1->InsertAfter(n, temp);
            system("cls");
            List_1->ShowAll();
        }
        temp = t;
    }
    system("cls");
    List_1->ShowAll();
    std::cout << "\n\n\t\t  1-Main Menu  \t\t\t  2-Try Again\n";
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        ValueDoublerInALinkedList();
        break;
    default:
        break;
    }
}
void ReverseList()
{
    system("cls");
    system("COLOR 60");
    SingularLinkedList *List_1 = new SingularLinkedList();
    // create the list from user input
    int value;
    while (std::cin >> value)
    {
        if (value == -1)
        {
            break;
        }
        List_1->InsertLast(value);
        system("cls");
        List_1->ShowAll();
    }
    system("cls");
    std::cout<<"Original List:\t";
    List_1->ShowAll();
    std::cout << "\nReversedList:\t";
    List_1->Reverse();
    List_1->ShowAll();
    std::cout << "\n\n\t\t  1-Main Menu  \t\t\t  2-Try Again\n";
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        ReverseList();
        break;
    default:
        break;
    }
}