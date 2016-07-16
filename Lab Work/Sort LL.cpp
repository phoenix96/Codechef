void linked_list::sort ()
{
  int count = 0, i;
  node *start = head;
  node *curr = NULL;
  node *trail = NULL;
  node *temp = NULL;

  while(start != NULL) { //grab count
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) { //for every element in the list

    curr = trail = head; //set curr and trail at the start node

    while (curr->next != NULL) { //for the rest of the elements in the list
      if (curr->data > curr->next->data) { //compare curr and curr->next

        temp = curr->next; //swap pointers for curr and curr->next
        curr->next = curr->next->next;
        temp->next = curr;

        //now we need to setup pointers for trail and possibly head
        if(curr == head) //this is the case of the first element swapping to preserve the head pointer
          head = trail = temp;
        else //setup trail correctly
          trail->next = temp;
        curr = temp; //update curr to be temp since the positions changed
      }
      //advance pointers
      trail = curr;
      curr = curr->next;
    }
  }
}
