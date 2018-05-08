import java.util.*;
import java.io.*;
import java.lang.*;

public class Connect_Nodes_At_Same_Level {
    static class Node {
        int data;
        Node left, right, next;

        public Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static void connect(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        q.add(null);

        while (!q.isEmpty()) {
            Node p = q.poll();
            if (p != null) {
                p.next = q.peek();
                if (p.left != null)
                    q.add(p.left);
                if (p.right != null)
                    q.add(p.right);
            } else if (!q.isEmpty())
                q.add(null);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.right.right = new Node(90);

        connect(root);

        System.out.println("Following are populated next pointers in \n"
                + "the tree (-1 is printed if there is no next)");
        System.out
                .println("next of " + root.data + " is " + ((root.next != null) ? root.next.data : -1));
        System.out.println("next of " + root.left.data + " is "
                + ((root.left.next != null) ? root.left.next.data : -1));
        System.out.println("next of " + root.right.data + " is "
                + ((root.right.next != null) ? root.right.next.data : -1));
        System.out.println("next of " + root.left.left.data + " is "
                + ((root.left.left.next != null) ? root.left.left.next.data : -1));
        System.out.println("next of " + root.right.right.data + " is "
                + ((root.right.right.next != null) ? root.right.right.next.data : -1));
    }
};