#include<stdio.h>
#include<dos.h>
main() {
	struct diskfree_t p;
	unsigned short total, available, free;
	int d, s;
	printf("\n Enter the drive number whose space is to calculated: ");
	scanf("%d",&d);
	s = _dos_getdiskfree(d,&p);
	if(s != 0)
		prinrf("Error: Fatal error occured!");
	else {
		total = p.total_clusters*p.sectors_per_cluster*p.bytes_per_sector;
		available = p.avail_clusters*p.sectors_per_cluster*p.bytes_per_sector;
		free = total - available;
		printf("\n Total space: %lu \n Used space: %lu \n Free space: %lu \n",total,available,free);
	}
}
