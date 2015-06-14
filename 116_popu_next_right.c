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

	struct TreeLinkNode *t, *p;

	root->next = 0;
	p = root;
	root = root->left;
	while (root) {
		t = root;
		while (p) {
			t->next = p->right;
			t = t->next;
			if (p = p->next) {
				t->next = p->left;
				t = t->next;
			} else {
				t->next = 0;
			}
		}
		p = root;
		root = root->left;
	}
}

int main(void)
{

}
