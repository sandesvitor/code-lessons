# Advanced Git

* Commit by hand (repo internals);
* Rebase
* Interactive Rebase
* rebase-on-pull
* Pull Requests
* External diff tools
* Advanced  logging
* Reflog
* Reset


In a first glance we would think Git, as a version controllers, stores only the diffs from version to version. But, behind the curtains, Git, in every commit, stores the whole tree structures of files and directories, following the hashes of each one of them, having a BLOB as a single file:

BLOB ==> TREE ==> COMMIT (every step of the way Git hashes)

*BLOB: Binary Large OBject*

However, we CANNOT BLOB twice, you only reffer to it, point to it. So, in a sense, we are not duplicating content.

On top of every commit it has A SINGLE TREE, that points to the root directory.

## 0. **Lets initialize the repo**:

```shell
$ git init bits
```

and cd to bits directory.

We can use tree command to inspect the tree-like structure of the files.

```shell
$ tree .git
.git
├── branches
├── config
├── description
├── HEAD
├── hooks
│   ├── applypatch-msg.sample
│   ├── commit-msg.sample
│   ├── fsmonitor-watchman.sample
│   ├── post-update.sample
│   ├── pre-applypatch.sample
│   ├── pre-commit.sample
│   ├── pre-merge-commit.sample
│   ├── prepare-commit-msg.sample
│   ├── pre-push.sample
│   ├── pre-rebase.sample
│   ├── pre-receive.sample
│   └── update.sample
├── info
│   └── exclude
├── objects
│   ├── info
│   └── pack
└── refs
    ├── heads
    └── tags

9 directories, 16 files
```
I will remove the hooks directory for this example with rm -rf .git/hooks, and we are ready to go!

## **1. Commit by Hand**:

Since git add <path> is an high-level command to add changes to commit, we can go on lower levels layer of the **onion-skin api**, using the *git hash-object* comand.

```shell
$ echo "So. The Spear-Danes in days gone by and the kings who ruled them had courage and greatness." | git hash-object -w --stdin

1e0d4ee88fa002edbf36d43ef9a8e0db042763bf
``` 

If we tree the .git directory again we can see the hashed object:

```shell
.git
├── branches
├── config
├── description
├── HEAD
├── info
│   └── exclude
├── objects
│   ├── 22
│   │   └── 0d4ee88fa002edbf36d43ef9a8e0db042763bft
│   ├── info
│   └── pack
└── refs
    ├── heads
    └── tags

9 directories, 5 files
```

Going on with this analogy, we can call this low-level layer commands as **plumbing commands** since they are for a plumber as we, the high end users, are for any noob using a toilet.

-p = preaty printing:

```shell
$ git cat-file -p 1e0d4ee88fa002edbf36d43ef9a8e0db042763bf

So. The Spear-Danes in days gone by and the kings who ruled them had courage and greatness.
```

-t = type of the file

```shell
$ git cat-file -t 1e0d4ee88fa002edbf36d43ef9a8e0db042763bf       [14:43:15]
blob
```

Now, let's mannually stage this changes:

```shell
$ git update-index --add -cacheinfo 100644 1e0d4ee88fa002edbf36d43ef9a8e0db042763bf beowulf.txt
```

\* the '100644' stads for changing the permission of the file!

```shell
$ git status                                                     [14:49:34]
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
	new file:   beowulf.txt

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	deleted:    beowulf.txt

``` 

From that alone we can see that, even if the file was created, it was deleted in sequence, meaning there is no file up to date. But remember, we need to have a **tree** to reference the **blobs**, so we can manually write our files.

Now, lets make another plumbing command:

```shell
$ git write-tree
bf8cc6234630f3dc28d6ea25c16590123d1c7ec1
```

Again, if we analyze the tree of the .git directory, we can see that another object file was created:

```shell
$ tree .git
.git
├── branches
├── config
├── description
├── HEAD
├── index
├── info
│   └── exclude
├── objects
│   ├── 1e
│   │   └── 0d4ee88fa002edbf36d43ef9a8e0db042763bf
│   ├── bf
│   │   └── 8cc6234630f3dc28d6ea25c16590123d1c7ec1
│   ├── info
│   └── pack
└── refs
    ├── heads
    └── tags

10 directories, 7 files
```

Now, for the sake of comparison, lets run the type flag (-t) and the preaty print flag (-p)  within the git cat-file command:

```shell
$ git cat-file -t bf8cc6234630f3dc28d6ea25c16590123d1c7ec1
tree

$ git cat-file -p bf8cc6234630f3dc28d6ea25c16590123d1c7ec1
100644 blob 1e0d4ee88fa002edbf36d43ef9a8e0db042763bf	beowulf.txt
```

Aha! Now we do have a tree structure to attach our blobs to it, and we can also note the **directory listing**

Now, things are not yet working properly (if we git status and git log there is not gonna be much of a difference). Next step is to commit-tree this changes:

```shell
$ git commit-tree bf8cc6234630f3dc28d6ea25c16590123d1c7ec1 -m "Crazy crazy commit"

5e6aad4a0e354bfbc98b9317d26e055f98faaaf4
```

Another object was created:

```shell
$ tree .git
.git
├── branches
├── config
├── description
├── HEAD
├── index
├── info
│   └── exclude
├── objects
│   ├── 1e
│   │   └── 0d4ee88fa002edbf36d43ef9a8e0db042763bf
│   ├── 5e
│   │   └── 6aad4a0e354bfbc98b9317d26e055f98faaaf4
│   ├── bf
│   │   └── 8cc6234630f3dc28d6ea25c16590123d1c7ec1
│   ├── info
│   └── pack
└── refs
    ├── heads
    └── tags

11 directories, 8 files
```


Looking at this tree, there are two major points that we still lack off. Firstly, we don't have a branch, as all branches are stated in the *refs* folder.

```shell
$ git update-ref refs/heads/master 5e6aad4a0e354bfbc98b9317d26e055f98faaaf4
``` 

This command will update the heads/master with the hash of commit.

```shell
$ tree .git                                                      [15:03:18]
.git
├── branches
├── config
├── description
├── HEAD
├── index
├── info
│   └── exclude
├── logs
│   ├── HEAD
│   └── refs
│       └── heads
│           └── master
├── objects
│   ├── 1e
│   │   └── 0d4ee88fa002edbf36d43ef9a8e0db042763bf
│   ├── 5e
│   │   └── 6aad4a0e354bfbc98b9317d26e055f98faaaf4
│   ├── bf
│   │   └── 8cc6234630f3dc28d6ea25c16590123d1c7ec1
│   ├── info
│   └── pack
└── refs
    ├── heads
    │   └── master
    └── tags

14 directories, 11 files
```

Now, we have solved *git log* problem:

```shell
$ git log

commit 5e6aad4a0e354bfbc98b9317d26e055f98faaaf4 (HEAD -> master)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 14:59:37 2021 -0300

    Crazy crazy commit
```

But we still don't have a file, so git status is not very happy!

```shell
git checkout HEAD -- beowulf.txt
```

**git checkout** command usually makes you switch from branch to branch. In this case, we want to go to the HEAD (the pointer of the linked list) and grab a file, in this case the beowulf.txt.

The "--" separates all the options, switches and parametters to a list of files.

Finally, we can say we know how to commit by hand!

```shell
$ cat beowulf.txt                                                [15:08:13]
So. The Spear-Danes in days gone by and the kings who ruled them had courage and greatness.
```

## 2. **Rebase, Reflog and Reset**:

Now, lets cd to another repo, *./javazone*.

In here, we alread have 3 commits:

```shell
$ git log

commit 1ef3f9515aeb85932a309540a82065a6d6308242 (HEAD -> master)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:23:30 2021 -0300

    Prophecy over wounds

commit dc00b0275ddccdea3a4f907b59ecee7cacc8f9c2
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:22:08 2021 -0300

    Noblest man

commit 03c54938ecd8e94423493c773917c85443456db0
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:21:02 2021 -0300

    Initial commit
```

If we check for branches, we can see that we only have *master* branch:

```shell
$ git branch

* master
```

And we are currently on the tip of master, as we can see taht both HEAD and master both point to that **top commit**:

```shell
commit 1ef3f9515aeb85932a309540a82065a6d6308242 (HEAD -> master)
```

So, lets make a new branch called "feature", and after that check the log:

```shell
$ git branch feature
$ git log

commit 1ef3f9515aeb85932a309540a82065a6d6308242 (HEAD -> master, feature)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:23:30 2021 -0300

    Prophecy over wounds

commit dc00b0275ddccdea3a4f907b59ecee7cacc8f9c2
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:22:08 2021 -0300

    Noblest man

commit 03c54938ecd8e94423493c773917c85443456db0
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:21:02 2021 -0300

    Initial commit
```

We can see that, besides HEAD and master, feature also points to the last commit.

Now, we made a simple change in the caesar.txt, and commit that change with -a flag to stage the changes.

```shell
commit 171774f8ff3367a7802480e5cbfbd2a6cf029e87 (HEAD -> master)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 20:13:05 2021 -0300

    Ruby lips

commit 1ef3f9515aeb85932a309540a82065a6d6308242 (feature)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:23:30 2021 -0300

    Prophecy over wounds

commit dc00b0275ddccdea3a4f907b59ecee7cacc8f9c2
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:22:08 2021 -0300

    Noblest man

commit 03c54938ecd8e94423493c773917c85443456db0
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:21:02 2021 -0300

    Initial commit
```

Both **master** and **HEAD** advanced together, pointing to the last commit, whereas **feature** is still pointing to the previous commit.

If we switch to **feature** with git checkout, **master** will still point to the last commit, whereas **HEAD** and **feature** will point to the previous commit, as shown bellow:

```shell
commit 1ef3f9515aeb85932a309540a82065a6d6308242 (HEAD -> feature)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:23:30 2021 -0300

    Prophecy over wounds

commit dc00b0275ddccdea3a4f907b59ecee7cacc8f9c2
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:22:08 2021 -0300

    Noblest man

commit 03c54938ecd8e94423493c773917c85443456db0
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:21:02 2021 -0300

    Initial commit
```

Checking out once again to **master**, I made a few changes in caesar.txt and commited those changes. Now we can see that **HEAD** went back to pointing at the same commit as **master**, the last one, whereas **feature** is two commits behind.

```shell
commit f35659a3279eb3cd57c7a9b51e91043f80bb5afd (HEAD -> master)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 20:48:06 2021 -0300

    Domestic fury

commit 171774f8ff3367a7802480e5cbfbd2a6cf029e87
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 20:13:05 2021 -0300

    Ruby lips

commit 1ef3f9515aeb85932a309540a82065a6d6308242 (feature)
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:23:30 2021 -0300

    Prophecy over wounds

commit dc00b0275ddccdea3a4f907b59ecee7cacc8f9c2
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:22:08 2021 -0300

    Noblest man

commit 03c54938ecd8e94423493c773917c85443456db0
Author: Vitor Sandes <sandesvitor@gmail.com>
Date:   Fri Jan 29 16:21:02 2021 -0300

    Initial commit
```

There are two ways to unify those branches: **merging** or **rebasing**.

Lets suppose that, in our local repo, we accidentally merge both branches, wanting to rebaswe then.

```shell
$ git merge feature feature                                       [20:57:29]
Merge made by the 'recursive' strategy.
 files/file3      | 1 +
 files/file4      | 1 +
 files/files1.txt | 1 +
 files/files2.txt | 1 +
 4 files changed, 4 insertions(+)
 create mode 100644 files/file3
 create mode 100644 files/file4
 create mode 100644 files/files1.txt
 create mode 100644 files/files2.txt
```

SO, I want to go back to the Domestic Fury commit (hash: f35659a3279eb3cd57c7a9b51e91043f80bb5afd)

```shell
$git reset --hard f35659a3279eb3cd57c7a9b51e91043f80bb5afd
HEAD is now at f35659a Domestic fury
```

Checking the **git reflog** command, we should have a better view of what happened till now:

```shell
$ git reflog

f35659a (HEAD -> master) HEAD@{0}: reset: moving to f35659a3279eb3cd57c7a9b51e91043f80bb5afd
50b4fc3 HEAD@{1}: merge feature: Merge made by the 'recursive' strategy.
be618ad HEAD@{2}: commit: Domestic fury 3
f35659a (HEAD -> master) HEAD@{3}: checkout: moving from feature to master
40cda43 (feature) HEAD@{4}: commit: Domestic fury 2
1ef3f95 HEAD@{5}: checkout: moving from master to feature
f35659a (HEAD -> master) HEAD@{6}: checkout: moving from master to master
f35659a (HEAD -> master) HEAD@{7}: commit: Domestic fury
171774f HEAD@{8}: checkout: moving from feature to master
1ef3f95 HEAD@{9}: checkout: moving from master to feature
171774f HEAD@{10}: checkout: moving from feature to master
1ef3f95 HEAD@{11}: checkout: moving from master to feature
171774f HEAD@{12}: commit: Ruby lips
1ef3f95 HEAD@{13}: commit: Prophecy over wounds
dc00b02 HEAD@{14}: commit: Noblest man
03c5493 HEAD@{15}: commit (initial): Initial commit
```

Yes, lets say we double down our regret and want to go back to the merge commit, represented in the reflog by **HEAD@{1}**. Firtly, we should rev-parse to get the hash, then we can just revert the change as we did before:

```shell
$ git rev-parse HEAD@{1}
50b4fc3825c289872cd07e07ef8ead73cb86d867
$ git reset --hard HEAD@{1}
HEAD is now at 50b4fc3 Merge branch 'feature'          
```

Ok, ok, lets go back to Domestic Fury commit (HEAD@{8})

```shell
git reset --hard HEAD@{3}
```

Using the **git log --graph --oneline --all** command, we can see the branching more clearly:

```shell
* be618ad (HEAD -> master) Domestic fury 3
* f35659a Domestic fury
* 171774f Ruby lips
| * 40cda43 (feature) Domestic fury 2
|/  
* 1ef3f95 Prophecy over wounds
* dc00b02 Noblest man
* 03c5493 Initial commit
```

Now, we'll rebase with master:

```shell
$ git rebase master
First, rewinding head to replay your work on top of it...
Applying: Domestic fury 2

$ git log --graph --oneline --all

* c844fb3 (HEAD -> feature) Domestic fury 2
* be618ad (master) Domestic fury 3
* f35659a Domestic fury
* 171774f Ruby lips
* 1ef3f95 Prophecy over wounds
* dc00b02 Noblest man
* 03c5493 Initial commit
```

It is clear that rebasing give us a single line, witch will mess up our **reflog**

Remember: ALWAYS DO THAT FROM MASTER!!!

```shell
$ git merge feature 
Updating be618ad..c844fb3
Fast-forward
 files/file3      | 1 +
 files/file4      | 1 +
 files/files1.txt | 1 +
 files/files2.txt | 1 +
 4 files changed, 4 insertions(+)
 create mode 100644 files/file3
 create mode 100644 files/file4
 create mode 100644 files/files1.txt
 create mode 100644 files/files2.txt
```

An example of **git log --graph --oneline --all** that shows a merged commit is shown bellow:

```shell
$ git log --graph --oneline --all

*   eb47129 (HEAD -> master) new commit in master
|\  
| * eb37217 (feature) added
| * d7011e3 Created files dir with 5 files
* | fa67934 new commit in feature
|/  
* 9791cf4 Insert new line
* 58583b6 First commit
```

Finally, if we checkout to master and merge, since we are at a single line, **master** will **fast forward to the top commit**

## 3. **Interactive Rebase**:

It is good practice to commit in an optimal way, not aiming to mark every checkpoint in your code, neither waiting two weeks of work to commit a really big chunk of all-together-code.

A good commit needs to tell a history within your code, need to be coheasive and decoupled (coupled means highly dependent from one another).

Lets say we have 5 files that tells the same story (made by the same commit in time). We can say that they have a coheasive history, but we can also say that they are coupled together.

We can use the "~" character to indicate an operator that will represents how many commits past, and -i flag to indicates that the rebase is interactive. So, typing **git rebase -i HEAD~5** means that we want to rebase five commits from where HEAD is pointing.