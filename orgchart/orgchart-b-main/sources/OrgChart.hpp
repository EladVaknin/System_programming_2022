/**
 *
 * @since 2022-05
 * AUTHORS: <Elad Vaknin>
 *  To see the whole process and the committees -
 *  https://github.com/EladVaknin/System_programming_2022 
 * 
 * https://www.geeksforgeeks.org/templates-cpp/
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

#pragma once
using namespace std;

namespace ariel {
    template<typename T=string>
    class OrgChart {
///////////////////////////////////////Node/////////////////////////////
        struct Node {
            T name;
            vector<Node *> childrens;
            Node *parent;

            Node(T &data) : name(data), parent(nullptr) {}

        };

/////////////////////////////////OrgChart///////////////////////////
        Node *root;

        Node *finde_node(T &search_name, Node *tmp) {
            if (tmp == nullptr) {
                return nullptr;
            }
            if (tmp->name == search_name) {
                return tmp;
            }
            for (auto s:tmp->childrens) {
                Node *tmp2 = finde_node(search_name, s);
                if (tmp2 != nullptr) {
                    return tmp2;
                }
            }
            return nullptr;
        }

    public:
        OrgChart() {
            root = nullptr;
        }

        ~OrgChart() = default;

        OrgChart(OrgChart<T> &orgchart) {   // copy constructor
            this->root = orgchart->root;
        }

        OrgChart(OrgChart<T> &&orgchart) noexcept {
            this->root = orgchart->root;
            orgchart.root = nullptr;
        }

        OrgChart &operator=(OrgChart<T> orgchart) {
            this->root = orgchart.root;
            orgchart.root = nullptr;
        }

        OrgChart &operator=(OrgChart<T> &&orgchart) noexcept {
            this->root = orgchart.root;
            orgchart.root = nullptr;
        }


        OrgChart &add_root(T x) {
            if (root == nullptr) {
                this->root = new Node(x);
            } else {    //replace
                this->root->name = x;
            }
            return *this;
        }


        OrgChart &add_sub(T x, T y) {
            check_node(root);   //if x is nullptr.
            auto *father = finde_node(x, root);
            if (father == nullptr) {
                throw invalid_argument("The names dosent exist");
            }
            father->childrens.push_back(new Node(y));
            return *this;

        }

//////////////////////////////////iterator////////////////////////////////////////////

        // implements iterator in sub class for the tree-functions https://programmer.group/principle-and-simple-implementation-of-c-stl-iterator-just-read-this-one.html
        enum Order_of_iterator {
            level_order, preorders, reverse_orders
        };

        class iterator {
        private :
            Node *current;
            //queues
            queue<Node *> queue_to_level;
            stack<Node *> stack_to_reverse;
            queue<Node *> queue_to_preorder;
            //enum object
            Order_of_iterator direction;

        public :
            iterator(Node *p, Order_of_iterator o) : current(p), direction(o) {
                check_input(p);
                // checks the order : 
                if (o == level_order) {
                    queue_to_level.push(p);
                } else if (o == preorders) {
                    preorder(p);
                    current = queue_to_preorder.front();
                    queue_to_preorder.pop();
                } else if (o == reverse_orders) {
                    reverse_bfs(p);
                    current = stack_to_reverse.top();
                    stack_to_reverse.pop();
                }

            }

            ~iterator() {};

            iterator(const iterator &i) {}

            iterator(iterator &&i) noexcept {}

            explicit iterator(Node *tmp = nullptr) : current(tmp) {
            }

            iterator bfs_step() {      // to next level order - becuse its tree we dont check if we visited becuse in thos tree cant be circuls
                if (queue_to_level.empty()) {
                    current = nullptr;
                } else {
                    current = queue_to_level.front();
                    queue_to_level.pop();
                    for (Node *tmp :current->childrens) {
                        queue_to_level.push(tmp);
                    }
                }
                return *this;
            }

            void reverse_bfs(Node *root) {
                queue<Node*> queue_to_reverse;
                queue_to_reverse.push(root);
                while (!queue_to_reverse.empty()) {
                    Node *tmp = queue_to_reverse.front();
                    queue_to_reverse.pop();
                    stack_to_reverse.push(tmp);
                    for (auto ritr = tmp->childrens.rbegin(); ritr != tmp->childrens.rend(); ritr++) {
                        queue_to_reverse.push(*ritr);
                    }
                }

            }

            void preorder(Node *tmp) {
                queue_to_preorder.push(tmp);
                for (Node *tmp2 : tmp->childrens) {
                    preorder(tmp2);        // recurseve becuse its goes left automatically
                }
            }

            void check_input(Node *tmp) {
                if (tmp == nullptr) {
                    throw invalid_argument("the tree is empty - cant run on the tree");
                }
            }


            void plus_plus_level_order() {
                bfs_step();
            }

            void plus_plus_reverse_order() {
                if (stack_to_reverse.empty()) {
                    current = nullptr;
                } else {
                    current = stack_to_reverse.top();
                    stack_to_reverse.pop();
                }
            }

            void plus_plus_preorder() {
                if (queue_to_preorder.empty()) {
                    current = nullptr;
                } else {
                    current = queue_to_preorder.front();
                    queue_to_preorder.pop();
                }
            }

            // ++ , =! , == ,*

            iterator &operator++() {
                switch (direction) {
                    case reverse_orders:
                        plus_plus_reverse_order();
                        break;

                    case preorders:
                        plus_plus_preorder();
                        break;

                    case level_order:

                        plus_plus_level_order();
                        break;
                }
                return *this;
            }

            iterator &operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            T &operator*() const {
                return this->current->name;
            }

      
            iterator &operator=(const iterator &i) = default;

            iterator &operator=(iterator &&i) noexcept {
                this->current = i.current;
                i.current = nullptr;
                return *this;
            }

            T *operator->() const {
                return &(this->current->name);
            }

            bool operator==(const iterator &i) const {
                return this->current == i.current;
            }

            bool operator!=(const iterator &i) const {
                return this->current != i.current;
            }
        };
///////////////////////////////////////////////////////////////////////////////////////////////////////


        iterator begin_level_order() {
            auto ite = iterator(root, level_order);
            ite.bfs_step();
            return ite;
        }

        iterator begin_reverse_order() {
            return iterator(root, reverse_orders);
        }

        iterator begin_preorder() {
            return iterator(root, preorders);
        }

        iterator end_level_order() {
            check_node(root);
            return iterator();
        }

        iterator reverse_order() {
            check_node(root);
            return iterator();
        }

        iterator end_preorder() {
            check_node(root);
            return iterator();
        }

        iterator begin() {
            return begin_level_order();
        }

        iterator end() {
            return end_level_order();
        }

        void check_node(Node *tmp) {
            if (tmp == nullptr) {
                throw invalid_argument("the tree is empty - cant run on the tree");
            }
        }

        static void print_tree(Node *tmp) {
            for (Node *t:tmp->childrens) {
                cout << " " << t->name << "on" << endl; /////// need to think how to get the father
                print_tree(t);
            }
        }

        friend ostream &operator<<(ostream &out, OrgChart &orgchart) {
            Node *tmp = orgchart.root;
            out << "-----" << tmp->name << "-----" << endl;
            print_tree(tmp);
            return out;
        }
    };
}

