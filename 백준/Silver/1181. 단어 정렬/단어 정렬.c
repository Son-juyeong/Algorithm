#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BST {
	char w[51];
	struct BST* left;
	struct BST* right;
}BST;

BST* insert(BST* B, char key[]) {
	BST* newb;
	if (B == NULL) {
		newb = (BST*)malloc(sizeof(BST));
		strcpy(newb->w, key);
		newb->left = NULL;
		newb->right = NULL;
		return newb;
	}
	else if (strlen(B->w) > strlen(key) || (strcmp(B->w, key) > 0 && strlen(B->w) == strlen(key)))
		B->left = insert(B->left, key);
	else if (strlen(B->w) < strlen(key) || (strcmp(B->w, key) < 0 && strlen(B->w) == strlen(key)))
		B->right = insert(B->right, key);
	return B;
}

void inorder(BST* B) {
	if (B) {
		inorder(B->left);
		printf("%s\n", B->w);
		inorder(B->right);
	}
}

int main()
{
	BST* word=NULL;
	char ww[51];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", ww);
		word = insert(word, ww);
	}
	inorder(word);
	return 0;
}