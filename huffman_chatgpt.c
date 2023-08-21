#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_NODES 256

struct TreeNode {
    unsigned char data;
    unsigned freq;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(unsigned char data, unsigned freq);
void swap_nodes(struct TreeNode** a, struct TreeNode** b);
void sort_nodes(struct TreeNode* nodes[], int n);
struct TreeNode* build_huffman_tree(unsigned char data[], unsigned freq[], int n);
void print_codes(struct TreeNode* root, int arr[], int top); 
void huffman_encode(unsigned char data[], unsigned freq[], int n); 

int main() {
    unsigned char data[] = {'a', 'b', 'c', 'd', 'e'};
    unsigned freq[] = {5, 9, 12, 13, 16};
    int n = sizeof(data) / sizeof(data[0]);

    huffman_encode(data, freq, n);

    return 0;
}

struct TreeNode* create_node(unsigned char data, unsigned freq) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void swap_nodes(struct TreeNode** a, struct TreeNode** b) {
    struct TreeNode* temp = *a;
    *a = *b;
    *b = temp;
}

void sort_nodes(struct TreeNode* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                swap_nodes(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}

struct TreeNode* build_huffman_tree(unsigned char data[], unsigned freq[], int n) {
    struct TreeNode* nodes[MAX_TREE_NODES];
    for (int i = 0; i < n; i++) {
        nodes[i] = create_node(data[i], freq[i]);
    }

    int remaining_nodes = n;
    while (remaining_nodes > 1){
        sort_nodes(nodes, remaining_nodes);

        struct TreeNode* left = nodes[0];
        struct TreeNode* right = nodes[1];
        struct TreeNode* parent = create_node(0, left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        nodes[1] = nodes[remaining_nodes - 1];
        remaining_nodes--;
    }

    return nodes[0];
}

void print_codes(struct TreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("'%c': ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffman_encode(unsigned char data[], unsigned freq[], int n) {
    struct TreeNode* root = build_huffman_tree(data, freq, n);
    int arr[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    print_codes(root, arr, top);
}
