#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

NodeData newNodeData(int n) {
    NodeData temp;
    temp.num = n;
    return temp;
} //end newNodeData

TreeNodePtr newTreeNode(NodeData d) {
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p -> data = d;
    p -> left = p -> right = NULL;
    return p;
} //end newTreeNode

TreeNode* buildTree(FILE * in) {
        char str[MaxWordSize+1];
        fscanf(in, "%s", str);
        if (strcmp(str, "@") == 0) return NULL;
        TreeNode* p = (TreeNode*) malloc(sizeof(TreeNode));
        p -> data.num = atoi(str);
        p -> left = buildTree(in);
        p -> right = buildTree(in);
        return p;
     } //end buildTree
TreeNodePtr findOrInsert(BinaryTree bt, NodeData d) {
    //searches for d; if found, return pointer to node containing d
    //else insert a node containing d and return pointer to new node
    TreeNodePtr newTreeNode(NodeData);

    if (bt.root == NULL) return newTreeNode(d);
    TreeNodePtr curr = bt.root;
    int cmp;
    while ((cmp = d.num - curr -> data.num)!= 0) {
        if (cmp < 0) { //try left
            if (curr -> left == NULL) return curr -> left = newTreeNode(d);
            curr = curr -> left;
        }
        else { //try right
            if (curr -> right == NULL) return curr -> right = newTreeNode(d);
            curr = curr -> right;
        }
    }
    //d is in the tree; return pointer to the node
    return curr;
} //end findOrInsert

void inOrder(FILE * out, TreeNodePtr node) {
    if (node!= NULL) {
        inOrder(out, node -> left);
        fprintf(out, " %d", node -> data.num);
        inOrder(out, node -> right);
    }
} //end inOrder

void serialize(TreeNode* root, FILE *fp)
{

    if (root == NULL)
    {
        fprintf(fp, "%c ", MARKER);
        return;
    }

// Else, store current node and recur for its children
    int intData =root->data.num; // extract value if the data is an integer
       fprintf(fp, "%d ", intData); // if the data is an integer

    serialize(root->left, fp);
    serialize(root->right, fp);
}

int getNodeLevel(int n) {

    //This function is to be used to insertBestBST function.
    //The number of nodes are stored in a static variable(To save the value and stop it from re-setting to 0 everytime the program runs) which is incremented each time a node is inserted.
    //The number of nodes is Given as a parameter to the getNodeLevel function which then increments the level variable whenever the level is not even.
    //The level variable that is returned represents the number of "2"'s/(levels) that can fit in the given amount of nodes.(highest power of 2 factors)
    //Gets the index of each data member/node, any member with an odd index goes on level 0



    int level = 0;
    while (n % 2 == 0) {
        level++;
        n /= 2;
    }
    return level;
}

void insertBestBST(int n, TreeNodePtr lastNode[]) {
    int getNodeLevel(int);
    TreeNodePtr newTreeNode(NodeData);
    NodeData newNodeData(int);
    static int numNodes = 0;

    TreeNodePtr p = newTreeNode(newNodeData(n)); //left and right are implicitly set to NULL
    numNodes++;
    int level = getNodeLevel(numNodes);

    //If the level is not 0(not a leaf node) left pointer is set to null(already the case)
    //If it is a leaf node, the left pointer is set to the node one level lower

    if (level > 0) p -> left = lastNode[level-1];

   //If this node exists and has a NULL right link,set it to the new node and increment the level variable
    if (lastNode[level+1] != NULL)
        if (lastNode[level+1] -> right == NULL)lastNode[level+1] -> right = p;

    // the current node is the last node processed at this level
    lastNode[level] = p;
} //end insertBestBST










TreeNodePtr finalizeBestBST(TreeNodePtr lastNode[]) {
    int m, n = MAX_HEIGHT - 1;
    // find the last entry in lastNode that is non-null
    // this is the root
    while (n > 0 && lastNode[n] == NULL) n--;
    TreeNodePtr root = lastNode[n];

    while (n > 0) {
       //Looking for highest node with a null right subtree. If not found the variable n
       //is decremented until a match is found.
        if (lastNode[n] -> right != NULL) n--;
        else {
           //Set the right child to the highest node in last node.
            TreeNodePtr tn = lastNode[n] -> left;
            m = n - 1;

           //Make sure that the node is not already in use in the left subtree of n
            while (m >= 0 && tn == lastNode[m]) {
                tn = tn -> right;
                m--;
            }
            if (m >= 0) lastNode[n] -> right = lastNode[m];
            n = m;
        } //end else
    } //end while
    return root;
} //end finalizeBST

