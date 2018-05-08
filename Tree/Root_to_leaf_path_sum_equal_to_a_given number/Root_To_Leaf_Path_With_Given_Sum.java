import java.util.*;
import java.io.*;
import java.lang.*;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class BinaryTree {
    Node root;

    boolean hasPathSum(int sum) {
        return hasPathSum(root, sum);
    }

    boolean hasPathSum(Node node, int sum) {
        if (node == null) {
            return (sum == 0);
        }
        boolean ans = false;
        int subsum = sum - node.data;
        if (subsum == 0 && node.left == null && node.right == null) {
            return true;
        }
        if (node.left != null) {
            ans = ans || hasPathSum(node.left, subsum);
        }
        if (node.right != null) {
            ans = ans || hasPathSum(node.right, subsum);
        }
        return ans;
    }
}

public class Root_To_Leaf_Path_With_Given_Sum {

    public static void main(String[] args) {
        int sum = 21;

        BinaryTree tree = new BinaryTree();
        tree.root = new Node(10);
        tree.root.left = new Node(8);
        tree.root.right = new Node(2);
        tree.root.left.left = new Node(3);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(2);

        System.out.println(tree.hasPathSum(sum));
    }
}