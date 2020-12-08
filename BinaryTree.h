#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#define MARKER '@'
#define MaxWordSize 10
#define MAX_HEIGHT 10 // max height for an optimum BST, total number of nodes must be less than 2 ^ (MAX_HEIGHT +1) - 1

typedef struct {
        int num;
     } NodeData;

     typedef struct treeNode_def {
        NodeData data;
        struct treeNode_def *left, *right;
     } TreeNode, *TreeNodePtr;

     typedef struct {
        TreeNode* root;
     } BinaryTree;

TreeNode* buildTree(FILE *);
NodeData newNodeData(int n);
TreeNodePtr newTreeNode(NodeData d);
TreeNodePtr findOrInsert(BinaryTree bt, NodeData d);
TreeNode* buildTree(FILE *);
void inOrder(FILE * out, TreeNodePtr node);

// OptimumBST functions
int getNodeLevel(int n);
void insertBestBST(int n, TreeNodePtr lastNode[]);
TreeNodePtr finalizeBestBST(TreeNodePtr lastNode[]);

void serialize(TreeNode* root, FILE *fp);


/* Sample code demonstrating the use of serialize function

FILE *fp = fopen("MyBSTtree.txt", "w");
if (fp == NULL)
{
puts("Could not open file");
return 0;
}
serialize(bst.root, fp); // where bst is of BinaryTree type
fclose(fp);
/* Sample code demonstrating the use of serialize function

FILE *fp = fopen("MyBSTtree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(bst.root, fp); // where bst is of BinaryTree type
    fclose(fp);




// The following code demonstrates reading a tree structure (serialized data)
// and extracting the node data from it and saving it into an integer array

FILE * in = fopen("data.txt", "r"); // input text file
        int arr[25] = {0};
        char str[120];
        int dex = 0;
        while(fscanf(in, "%s", str)!=EOF){ // or while(fscanf(in, "%s", str)==1)
                if (strcmp(str, "@") == 0)
                    continue; // ignore @ marker
                else
                arr[dex++] = atoi(str); // extract the integer from the string
                                        // and populate the array
        }
*/

#endif // BINARYTREE_H_INCLUDED
