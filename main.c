/** Following is the step-by-step guide to the solution of Assignment 4. Several of the steps have already been
completed.
In this assignment, you are required to:
1- build a BST with random integers and save it as a serialized text file
2- Traverse this BST in order and save it to another file ( this file will be a sorted list of integers)
3- Feed this set of random integers to the optimum BST to build an Optimum BST and then write this optimum BST
as a serialized text file.

Here is the list of steps:
1. Change NodeData definition
(Already done)
2. Update newNodeData function
(Already done)

TODO 3. write random integers to a file, change its mode to 'w'
    in a loop write
    fprintf(in, "%d ", rand() );            //Done???
4. open that file, read random integers and build the tree
 use the following statement to read:
    while (fscanf(in, "%s", word)!= EOF)
(Already done)

5. extract integer out of the data read as string from file using
        atoi() function
(Already done)

6. Make sure, the node definition and AddNode functions have been consistently
declared/defined and called
(partly done)

7. Include serialize.h header file and move Node definitions and function prototypes
to the header file and ensure no redefinitions!
(Already done)

8. Comment out the unnecessary or irrelevant functions rather than trying to fix it!
(Already done)

9. make appropriate changes in the findOrInsert function in the context of
new definition of NodeData
(Already done)

TODO 10. save the BST as a serialized file

TODO 11. open a new text file for writing and write above BST's inOrder traversal to this file.

// TODO 12. close all files!

// TODO 13. reopen file of sorted list of integers

// TODO 14. Major task: using optimum BST algorithms build and save an optimum BST as a serialized text file!

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

#define MAXNODE 20 // Warning! make sure MAXNODE is always set smaller than the range
#define RANGE 100 //for distinct set of random integers
#define OFFSET 10


     int main() {
        char word[MaxWordSize+1];
        int data;
        int data1;
        FILE * in = fopen("..//data//randomintegers.txt", "w");
        FILE * out = fopen("..//data//normalbst.txt", "w");

        // TODO 3 Write the code to generate distinct random integers and save these
        for(int i =0;i<RANGE;i++) {
            fprintf(in, "%d ", rand());
        }
        fclose(in); //File closure

        in = fopen("..//data//randomintegers.txt", "r"); // reopen file to build a BST
                            // with random integers from file 'in'
        BinaryTree bst;

        bst.root=NULL;


        ////////////////Create and print normal binary tree///////

         while (fscanf(in, "%s", word)!= EOF) {
             data1 = atoi(word);
             if (bst.root == NULL){
                    bst.root = newTreeNode(newNodeData(data1));
                    serialize(bst.root,out);}
             else {
                 TreeNodePtr node = findOrInsert(bst, newNodeData(data1));
                    serialize(node,out);
             }
         }



        fclose(out); /////File closure




         ////////////////////////////////Serializing BST////////////////////////////////
         //TODO 10. save the BST as a serialized file //done
         FILE *serialTxt = fopen("..//data//SerializedTree.txt", "w");
         if (serialTxt == NULL)
         {
             puts("Could not open file");
             return 0;
         }
         serialize(bst.root, serialTxt); // where bst is of BinaryTree type

         fclose(serialTxt);/////File closure

         ////////////////////////////////Serializing End////////////////////////////////

         //TODO 11. open a text file for writing and write above BSTs inOrder traversal to this file. //done
         ////////////////////////////////In Order BST////////////////////////////////
         FILE *InOrderTxt = fopen("..//data//InOrder.txt", "w");
         if (serialTxt == NULL)
         {
             puts("Could not open file");
             return 0;
         }
        inOrder(InOrderTxt,bst.root); // where bst is of BinaryTree type

        fclose(InOrderTxt);/////File closure

         //////////////////////////////// In Order End////////////////////////////////

        // TODO 12. close all files!// done





        // TODO 13. reopen file of sorted list of integers
        ////////////////////////File opening ////////////////////////

        FILE *optTree = fopen("..//data//InOrder.txt", "r");

         int n;
         TreeNodePtr lastNode[MAX_HEIGHT];
         for (n = 0; n < MAX_HEIGHT; n++)
             lastNode[n] = NULL;
         ////////////////////////End of File opening ////////////////////////

         // TODO 14. Major task: using optimum BST algorithms build and save an optimum BST as a serialized text file!

         while (fscanf(optTree, "%d", &n) == 1)
             insertBestBST(n, lastNode);
         while (fscanf(in, "%d", &n) == 1)
             insertBestBST(n, lastNode);

            /// distinct sorted random integer generation logic ends
         bst.root = finalizeBestBST(lastNode);
         FILE *fp = fopen("..//data//MyOPTBSTtree.txt", "w");

         // basic file error check
         if (fp == NULL)
         {
             puts("Could not open file");
             return 0;
         }
         serialize(bst.root, fp);
         fclose(fp);




     } // end main
