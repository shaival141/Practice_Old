import java.util.*;
import java.lang.*;
import java.io.*;

/**
 * Do inorder traversal of tree, and check if the it is sorted at every point,
 * by maintaining a pointer to previously occuring node
 */

class Node {
    Node left, right;
    int data;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
};

class BinaryTree {
    Node root, prev;

    boolean isBST() {
        prev = null;
        return isBST(root);
    }

    boolean isBST(Node node) {
        if (node != null) {
            if (!isBST(node.left))
                return false;
            if (prev != null && node.data <= prev.data)
                return false;
            prev = node;
            return isBST(node.right);
        }
        return true;
    }

};

public class Check_If_Tree_Is_BST {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(4);
        tree.root.left = new Node(21);
        tree.root.right = new Node(5);
        tree.root.left.left = new Node(1);
        tree.root.left.right = new Node(3);

        if (tree.isBST())
            System.out.println("IS BST");
        else
            System.out.println("Not a BST");
    }
}