#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE * fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("cidrs.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int ips_total = 0;
  int bit = 0;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		bit = 32 - atoi(strchr(line, '/') + 1);
		ips_total += 1 << bit;
	}

	printf("Total IPs in CIDR: %d\n", ips_total);

	fclose(fp);

	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

