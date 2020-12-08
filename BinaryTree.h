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



#endif // BINARYTREE_H_INCLUDED
