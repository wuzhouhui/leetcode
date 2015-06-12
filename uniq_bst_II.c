/*
 * vim: ts=4 sw=4 sts=4 et
 */
/*
 * output limit exceeded
 */
#include <stdlib.h>

#define STEP	8

struct TreeNode {
    int	val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int numTrees(int);

static struct TreeNode **do_gen(int start, int end, int *ret_size)
{
    struct TreeNode **roots, **left, **right;
    int	p, maxp, left_size, right_size;
    int	i, j, k;

    p = 0;
    maxp = STEP;
    roots = malloc(maxp * sizeof(struct TreeNode*));

    if (start > end) {
        roots[0] = 0;
        *ret_size = 1;
        return(roots);
    }

    for (i = start; i <= end; i++) {
        left = do_gen(start, i - 1, &left_size);
        right = do_gen(i + 1, end, &right_size);
        for (j = 0; j < left_size; j++) {
            for (k = 0; k < right_size; k++) {
                if (p >= maxp) {
                    maxp += STEP;
                    roots = realloc(roots, maxp * sizeof(struct TreeNode *));
                }
                roots[p] = malloc(sizeof(struct TreeNode));
                roots[p]->left = left[j];
                roots[p]->right = right[k];
                p++;
            }
        }
    }
    free(left);
    free(right);
    *ret_size = p;
    return(roots);
}

struct TreeNode **generateTrees(int n, int *returnSize)
{
    return(do_gen(1, n, returnSize));
}

#include <stdio.h>
int main(void)
{
    struct TreeNode **roots;
    int r, i;
    for (i = 0; i < 5; i++) {
        roots = generateTrees(i, &r);
        printf("%d, %d\n", numTrees(i), r);
    }
    return(0);
}
