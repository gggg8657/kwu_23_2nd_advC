#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

char s[200][100];
int s_num[200];
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
int initial_booklist(char** name, int* num, FILE* f) {
	char temp[100];
	int i = 0;
	while (1) {
		if (feof(f)) break;
		fgets(temp, sizeof(temp), f);
		name[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy(name[i], temp);
		name[i][strlen(name[i]) - 1] = '\0';
		num[i] = 3;
		i++;
	}
	num[0] = 0;
	num[13] = 0;
	return i;
}
void manage_booklist(char** name, int* num, int bor) {
	static int k = 0;
	static char bo[21][100] = { 0, };
	if (0 <= bor && bor <= 20) {
		num[bor]--;
		if (num[bor] >= 0) {
			printf("%s µµº≠∞° ¥Î√‚µ«æ˙Ω¿¥œ¥Ÿ(«ÿ¥Á µµº≠¥¬ %d±« ≥≤æ“Ω¿¥œ¥Ÿ)\n", name[bor], num[bor]);
			strcpy(bo[k], name[bor]);
			k++;
			printf("[¥Î√‚«ˆ»≤]--------------\n");
			for (int i = 0; i < k; i++) {
				printf("%s\n", bo[i]);
			}
		}
		else {
			printf("%s µµº≠¥¬ «ˆ¿Á ∏µŒ ¥Î√‚µ» ªÛ≈¬¿‘¥œ¥Ÿ\n", name[bor]);
			printf("[¥Î√‚«ˆ»≤]--------------\n");
			for (int i = 0; i < k; i++) {
				printf("%s\n", bo[i]);
			}
		}
	}
	else {
		printf("∫∏¿Ø«œ¡ˆ æ ¿∫ µµº≠¿« ID¿‘¥œ¥Ÿ\n");
	}
}
void print_booklist(char** name, int* num, int i, int n, char *admin) {
	if (strcmp(admin, "∞¸∏Æ¿⁄") == 0 || strcmp(admin, "admin") == 0) {
		printf("-----------¿˙¿Â∞Ì----------\n");
		for (int i = 0; i < n; i++) {
			if (s_num[i] != 100) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("[%d] %s(%d)\n", i + 1, s[i], s_num[i]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				printf("[%d] %s(%d)\n", i + 1, s[i], s_num[i]);
			}
		}
	}
	printf("-------∫∏¿Ø¡ﬂ¿Œ µµº≠-------\n");
	for (int j = 0; j < i; j++) {
		printf("[%d] %s(%d)\n", j + 1, name[j], num[j]);
	}
	printf("---------------------------\n");
}
int admin_check(char* data, char* input) {
	if (strcmp(input, data) == 0) return 1;
	else return 0;
}
int fill(char** name, int* num, FILE* sto, FILE* f, int m) {
	int n = 0;
	char temp[4];
	for (n = 0;; n++) {
		if (feof(sto)) break;
		fgets(s[n], 100, sto);
		s[n][strlen(s[n])-5] = '\0';
		s_num[n] = 100;
	}
	for (int i = 0; i < m; i++) {
		if (num[i] == 0) {
			num[i] = 3;
			for (int j = 0; j < n; j++) {
				if (strcmp(name[i], s[j]) == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("%s √§øÏ¥¬ ¡ﬂ.", s[j]);
					Sleep(700);
					printf(".");
					Sleep(700);
					printf(".\n");
					Sleep(700);
					s_num[j] -= 3;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
			}
		}
	}
	return n;
}
int main() {
	struct book {
		char** name;
		int* num;
	}b;
	char trash[100];
	FILE* f = fopen("", "r");
	FILE* data = fopen("", "r");
	FILE* storage = fopen("", "r");
	fgets(trash, 100, storage);
	b.name = (char**)malloc(sizeof(char*) * 100);
	b.num = (int*)malloc(sizeof(int) * 100);
	char admin[10];
	int k = 0;
	int i = initial_booklist(b.name, b.num, f);
	int n = 0;
	while (1) {
		printf("∏µÂ º≥¡§(∞¸∏Æ¿⁄/¿Ø¿˙) : ");
		scanf("%s", admin);
		if (strcmp(admin, "∞¸∏Æ¿⁄") == 0 || strcmp(admin, "admin") == 0) {
			printf("»Æ¿Œµ«æ˙Ω¿¥œ¥Ÿ.");
			Sleep(1000);
			system("cls");
			char aid[100], temp[100], apw[100];
			fgets(temp, 100, data);
			temp[strlen(temp) - 1] = '\0';
			while (1) {
				char id[100] = "ID  ";
				printf("ID : ");
				scanf(" %s", aid);
				strcat(id, aid);
				if (admin_check(temp, id)) {
					fgets(temp, 100, data);
					while (1) {
						char pw[100] = "PW  ";
						printf("PW : ");
						scanf(" %s", apw);
						strcat(pw, apw);
						if (admin_check(temp, pw)) {
							printf("∞¸∏Æ¿⁄ ∏µÂ Ω««‡¡ﬂ.");
							Sleep(700);
							printf(".");
							Sleep(700);
							printf(".\n");
							Sleep(1400);
							printf("∫∏¿Ø µµº≠ ∫“∑Øø¿¥¬ ¡ﬂ.");
							Sleep(700);
							printf(".");
							Sleep(700);
							printf(".\n");
							Sleep(700);
							printf("∫Œ¡∑«— µµº≠ ¿Á∞Ì √§øÏ¥¬ ¡ﬂ.");
							Sleep(700);
							printf(".");
							Sleep(700);
							printf(".\n");
							Sleep(700);
							n = fill(b.name, b.num, storage, f, i);
							system("cls");
							break;
						}
						else {
							printf("¿ﬂ∏¯µ» PW¿‘¥œ¥Ÿ. ¥ŸΩ√ ¿‘∑¬«ÿ ¡÷ººø‰\n");
						}
					}
					break;
				}
				else {
					printf("¿ﬂ∏¯µ» ID¿‘¥œ¥Ÿ. ¥ŸΩ√ ¿‘∑¬«ÿ ¡÷ººø‰\n");
				}
			}
			break;
		}
		else if (strcmp(admin, "¿Ø¿˙") == 0 || strcmp(admin, "user") == 0) {
			printf("»Æ¿Œµ«æ˙Ω¿¥œ¥Ÿ.");
			Sleep(1000);
			system("cls");
			printf("∫∏¿Ø µµº≠ ∫“∑Øø¿¥¬ ¡ﬂ.");
			Sleep(700);
			printf(".");
			Sleep(700);
			printf(".\n");
			Sleep(1400);
			system("cls");
			break;
		}
		else {
			if (k > 1) {
				printf("¿‘∑¬ ∞°¥… »Ωºˆ∏¶ √ ∞˙«œø© «¡∑Œ±◊∑•¿Ã ¿⁄µø¡æ∑· µÀ¥œ¥Ÿ.");
				Sleep(1400);
				printf(" 3");
				Sleep(1000);
				printf(" 2");
				Sleep(1000);
				printf(" 1");
				Sleep(1000);
				printf("\n«¡∑Œ±◊∑• ¡æ∑·.");
				return 0;
			}
			else {
				printf("¿ﬂ∏¯µ» type¿« ∏µÂ¿‘¥œ¥Ÿ. ¥ŸΩ√ ¿‘∑¬«ÿ¡÷ººø‰. (≥≤¿∫ ¿‘∑¬ »Ωºˆ %d)", 2 - k);
				Sleep(3000);
				system("cls");
			}
		}
		k++;
	}
	print_booklist(b.name, b.num, i, n, admin);
	int bor;
	for (int j = 0; j < 22; j++) {
		printf("\n¥Îø© «“ µµº≠¿« ID∏¶ ¿‘∑¬«ÿ ¡÷ººø‰(«¡∑Œ±◊∑• ¡æ∑· : 0) ");
		scanf("%d", &bor);
		if (bor == 0) break;
		manage_booklist(b.name, b.num, bor - 1);
	}
	fclose(f);
	fclose(data);
}
