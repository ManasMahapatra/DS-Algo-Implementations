//This files contains different algorithms to construct trees from single or multiple provided 
//traversal arrays. It also provides algorithms to compare them.
//Node Structure for constructing trees
struct node {
    //This will point to theleft child of the current node
    node* left;
    //This will contain the data
    int data;
    //This will point to the right child of current node
    node* right;
};
class Construction {
    bool compareInPrePost(int inOrder[],int preOrder[],int postOrder[]) {
        //Get the length of array
        int arrayLengthInOrder = (sizeof(inOrder)/sizeof(inOrder[0]));
        int arrayLengthPreOrder = (sizeof(inOrder)/sizeof(preOrder[0]));
        int arrayLengthPostOrder = (sizeof(inOrder)/sizeof(postOrder[0]));
        //Check if all the lengths are equal; if not false;
        if ((arrayLengthInOrder == arrayLengthPreOrder) && (arrayLengthPreOrder == arrayLengthPostOrder)) {
            //If they all are empty, of course they are same
            if (arrayLengthInOrder == 0) {
                return true;
            }
            //If they consist one element, it should be equal; else false
            if ((inOrder[0] == preOrder[0]) && (preOrder[0] == postOrder[0])) {
                return true;
            } else {
                return false;
            }
            //Store root element
            int rootElement = preOrder[0];
            //Locate the root element in Inorder
            int rootLocationInOrder = -1;
            for (int i = 0;i < arrayLengthInOrder;i++) {
                if (inOrder[i] == rootElement) {
                    rootLocationInOrder = i;
                    break;
                }
            }
            //Figure out the { LEFT SUBTREE } and { RIGHT SUBTREE } in the given arrays
            //--------InOrder----------
            //{ LEFT SUBTREE } = from 0th index to (rootLocationInOrder - 1)
            //{ RIGHT SUBTREE } = from (rootLocationInOrder + 1) to last element
            int leftSubInOrder[rootLocationInOrder];
            for (int i = 0;i<rootLocationInOrder;i++){
                leftSubInOrder[i] = inOrder[i];
            }
            int rightSubInOrder[arrayLengthInOrder - rootLocationInOrder + 1];
            for (int i = 0;i < (arrayLengthInOrder - rootLocationInOrder + 1);i++) {
                rightSubInOrder[i] = inOrder[rootLocationInOrder + i + 1];
            }
            //---------PreOrder--------
            //{ LEFT SUBTREE } = from 1st index till length of (rootLocationIndex)
            //If there's no root element in Inorder they aren't same
            if (rootLocationInOrder == -1) { return false; }
            //bool resLeft = compareInPrePost();

        } else {
            return false;
        }
        //Store root element
        int rootElement = preOrder[0];
        //Locate the root element in Inorder
        int rootLocationInOrder = -1;
        for (int i = 0;i < arrayLengthInOrder;i++) {
            if (inOrder[i] == rootElement) {
                rootLocationInOrder = i;
                break;
            }
        }
        //If there's no root element in Inorder they aren't same
        if (rootLocationInOrder == -1) { return false; }



    }
};