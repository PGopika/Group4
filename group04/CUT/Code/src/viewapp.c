int view_bookings()
{
	book_app *ptr;
	if(!start2)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}printf("\n.....viewing appointments with patient info....\n");
	printf("\nAADHAR_NO  NAME  SLOT\n");
	for(ptr=start2;(ptr);ptr->next)
	{
		printf("\n%d---%s---%s\n",ptr->aan,ptr->pat_name,ptr->book_slot);
	}
	return EXIT_SUCCESS;
}


