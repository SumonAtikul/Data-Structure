Node* findMax()
{
    if(head==NULL)
    {
        cout<<"empty";
        return NULL;
    }
    Node* max=head;
    while(head!=NULL)
    {
        if(head->data>max->data)
        {
            max=head;
        }
        head=head->next
    }
    return max;

}
