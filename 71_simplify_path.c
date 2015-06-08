#include <stdlib.h>
#include <string.h>

struct node {
    char *path;
    struct node *next;
};

static struct node *stack;

static void push(const char *path)
{
    struct node *tmp;

    tmp = malloc(sizeof(struct node));
    tmp->path = strdup(path);
    tmp->next = stack;
    stack = tmp;
}

static char *top(void)
{
    return(stack->path);
}

static char *pop(void)
{
    struct node *tmp;
    char *path;

    tmp = stack;
    stack = stack->next;
    path = tmp->path;
    free(tmp);
    return(path);
}

char *simplifyPath(char *path)
{
    if (!path || !path[0])
        return(strdup(""));

    static char tmppath[4096];
    struct node *head, *tmp;
    int     i, j;

    stack = 0;
    for (i = 0; path[i]; ) {
        switch (path[i]) {
        case '/':
            if (!i)
                push("/");
            i++;
            break;
        case '.':
            if (!path[i+1] || path[i+1] == '/') {
                i++;
            } else if (path[i+1] == '.') {
                if (!path[i+2] || path[i+2] == '/') {
                    if (!stack) {
                        push("..");
                    } else if (strcmp("/", top())) {
                        free(pop());
                    }
                    i += 2;
                } else {
                    for (j = 0; path[i] && path[i] != '/'; i++)
                        tmppath[j++] = path[i];
                    tmppath[j] = 0;
                    push(tmppath);
                }
            } else {
                for (j = 0; path[i] && path[i] != '/'; i++)
                    tmppath[j++] = path[i];
                tmppath[j] = 0;
                push(tmppath);
            }
            break;
        default:
            for (j = 0; path[i] && path[i] != '/'; i++)
                tmppath[j++] = path[i];
            tmppath[j] = 0;
            push(tmppath);
        }
    }

    if (!stack)
        return(strdup(""));
    head = 0;
    while (stack) {
        tmp = stack;
        stack = stack->next;
        tmp->next = head;
        head = tmp;
    }

    i = 0;
    while (head) {
        tmp = head;
        head = head->next;
        if (!i) {
            if (tmp->path[0] == '/') {
                tmppath[i++] = '/';
            } else if (!strcmp(tmp->path, "..")) {
                tmppath[i++] = '.', tmppath[i++] = '.';
            } else {
                tmppath[i++] = '/';
                memcpy(tmppath+i, tmp->path, strlen(tmp->path));
                i += strlen(tmp->path);
            }
        } else {
            if (i != 1)
                tmppath[i++] = '/';
            memcpy(tmppath+i, tmp->path, strlen(tmp->path));
            i += strlen(tmp->path);
        }
        free(tmp->path);
        free(tmp);
    }

    tmppath[i] = 0;
    return(strdup(tmppath));
}

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%s\n", simplifyPath(argv[1]));
    return(0);
}
