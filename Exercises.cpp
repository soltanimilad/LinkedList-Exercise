#include "Menus.cpp"
void JusephusGame();
void SymmetricalArrayChecker();
void InsertionSortOnTwoLinkedList();
void ValueDoublerInALinkedList();
int main()
{
    int choice;
    system("COLOR B0");
    std::cout << "\n\n\n\n\t\t1-Josephus Death Game with Linked List\t"
              << "\t\t2-Symmetrical Array Checker\n\n\n\n"
              << "\t\t3-Insertion Sort on two Linked List\t"
              << "\t\t4-Value Doubler in a Linked List\n\n\n\n"
              << "\t\t\t\t\t\t\t5-Revrese List\n\n\n\n";
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        JusephusGame();
        break;
    case 2:
        SymmetricalArrayChecker();
        break;
    case 3:
        InsertionSortOnTwoLinkedList();
        break;
    case 4:
        ValueDoublerInALinkedList();
        break;
    case 5:
        ReverseList();
        break;
    default:
        main();
        break;
    }
}