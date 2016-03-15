/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int checkValid(char * dob){
	int dd, mm, yyyy, i;
	if ((*(dob + 2) != '-') && (*(dob + 5) != '-'))return -1;
	dd = *(dob)-'0';
	dd = dd * 10 + (*(dob + 1) - '0');
	mm = *(dob + 3) - '0';
	mm = mm * 10 + (*(dob + 4) - '0');
	yyyy = *(dob + 6) - '0';
	for (i = 7; i <= 9; i++)
		yyyy = yyyy * 10 + (*(dob + i) - '0');
	if (yyyy % 4 == 0){
		if (mm == 2){
			if (dd <= 0 || dd>29)return -1;
		}
	}
	else{
		if (mm = 2){
			if (dd <= 0 || dd>28)return -1;
		}
	}
	if (dd <= 0 || dd>31 || mm <= 0 || mm>12 || yyyy <= 0 || yyyy>9999)
		return -1;
	else return 0;

}
int isOlder(char *dob1, char *dob2){
	int result1, result2, i;
	int yyyy1, yyyy2, mm1, mm2, dd1, dd2;
	result1 = checkValid(dob1);
	result2 = checkValid(dob2);
	if (result1 == -1 || result2 == -1)return -1;
	dd1 = *(dob1)-'0';
	dd1 = dd1 * 10 + (*(dob1 + 1) - '0');
	mm1 = *(dob1 + 3) - '0';
	mm1 = mm1 * 10 + (*(dob1 + 4) - '0');
	yyyy1 = *(dob1 + 6) - '0';
	for (i = 7; i <= 9; i++){
		yyyy1 = yyyy1 * 10 + (*(dob1 + i) - '0');
	}
	dd2 = *(dob2)-'0';
	dd2 = dd2 * 10 + (*(dob2 + 1) - '0');
	mm2 = *(dob2 + 3) - '0';
	mm2 = mm2 * 10 + (*(dob2 + 4) - '0');
	yyyy2 = *(dob2 + 6) - '0';
	for (i = 7; i <= 9; i++)
		yyyy2 = yyyy2 * 10 + (*(dob2 + i) - '0');
	if (yyyy1 > yyyy2)return 2;
	else if (yyyy1 < yyyy2)return 1;
	else{
		if (mm1 > mm2)return 2;
		else if (mm1 < mm2)return 1;
		else{
			if (dd1>dd2)return 2;
			else if (dd1 < dd2)return 1;
			else return 0;
		}
	}

}
