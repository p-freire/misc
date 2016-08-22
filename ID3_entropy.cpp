#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STR_BUFFER 50

double log2(double value)
{
	return log(value) / log(2.0);
}

double entropy(int pos_inst, int neg_inst, int total_inst)
{
	double pos_rate = (double)pos_inst / (double) total_inst;
	double neg_rate = (double)neg_inst / (double) total_inst;

	return pos_inst > 0 && neg_inst > 0 ? ((-1.0) * pos_rate * log2(pos_rate)) - (neg_rate * log2(neg_rate)) : 0.0;
}

int main()
{
	int pos_inst, neg_inst, total_inst, total_attr, number_of_values;
	char attribute_name[STR_BUFFER];
	double master_entropy, information_gain = 0.0;

	printf("Entropy of the whole set\n");
	printf("\tNumber of positive and negative instances: ");
	scanf("%d %d", &pos_inst, &neg_inst);
	total_inst = pos_inst + neg_inst;
	master_entropy = entropy(pos_inst, neg_inst, total_inst);
	information_gain = master_entropy;

	printf("\nCalculated entropy! Now please input attribute name: ");
	scanf(" %[^\n]s", attribute_name);
	printf("\nPlease input number of possible values for the attribute [%s]: ", attribute_name);
	scanf("%d", &number_of_values);

	for(int i = 0; i < number_of_values; ++i)
	{
		printf("Attribute: %s\n", attribute_name);
		printf("\tIteration %d/%d\n", i + 1, number_of_values);
		printf("\tNumber of positive and negative instances for value %d: ", i + 1);
		scanf("%d %d", &pos_inst, &neg_inst);
		printf("\n\n");
		total_attr = pos_inst + neg_inst;
		information_gain -= ((double)total_attr / (double)total_inst) * entropy(pos_inst, neg_inst, total_attr);
	}

	printf("\n-------------------------\n");
	printf("SUMMARY FOR ATTRIBUTE [%s]\n", attribute_name);
	printf("Entropy = %lf\n", master_entropy);
	printf("Information gain = %lf\n", information_gain);

	return 0;
}