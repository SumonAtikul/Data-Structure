voidDoublyLinkedlist::findMax()
{
    int Max = head->data;
    while(head!=NULL)
    {
        if(head->data > Max)
        {
            Max=head->data;
        }
        head=head->next;
    }
    printf("Max = %d", Max);
}
