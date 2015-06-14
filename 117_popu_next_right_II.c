
struct TreeLinkNode {
    int	val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};

void connect(struct TreeLinkNode *root)
{
    if (!root)
        return;
    struct TreeLinkNode *parent, *t, *next;

    root->next = 0;
    parent = root;
    root = root->left ? root->left : root->right;
    while (root) {
        t = root;
        while (parent) {
            next = 0;
            while (parent && !next) {
                if (!parent->left && !parent->right) {
                    parent = parent->next;
                    continue;
                }

                if (parent->left && !parent->right) {
                    if (parent->left == t) {
                        parent = parent->next;
                        continue;
                    }
                    next = parent->left;
                    break;
                }
                if (!parent->left && parent->right) {
                    if (parent->right == t) {
                        parent = parent->next;
                        continue;
                    }
                    next = parent->right;
                    break;
                }
                if (parent->left && parent->right) {
                    if (parent->left == t) {
                        next = parent->right;
                        break;
                    } else {
                        if (parent->right == t) {
                            parent = parent->next;
                            continue;
                        } else {
                            next = parent->left;
                            break;
                        }
                    }
                }
            }
            t->next = next;
            t = next;
        }
        parent = root;
        while (root) {
            if (root->left || root->right) {
                root = root->left ? root->left : root->right;
                break;
            } else {
                root = root->next;
            }
        }
    }
}

#include <stdlib.h>

int main(void)
{
    struct TreeLinkNode *root = malloc(sizeof(struct TreeLinkNode));
    root->val = 1;
    root->left = malloc(sizeof(struct TreeLinkNode));
    root->left->val = 2;
    root->left->left = calloc(1, sizeof(struct TreeLinkNode));
    root->left->left->val = 4;
    root->left->right = calloc(1, sizeof(struct TreeLinkNode));
    root->left->right->val = 5;
    root->right = calloc(1, sizeof(struct TreeLinkNode));
    root->right->val = 3;
    connect(root);
    return(0);
}
