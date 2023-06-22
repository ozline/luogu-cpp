# luogu-cpp

I store the data structure and algorithm questions I have done in this repo, all problems comes from luogu.

welcome to visit my luogu profile: [https://www.luogu.com.cn/user/70667](https://www.luogu.com.cn/user/70667)

# Note

in `list` dictionary, you will find that all folders are formatted as numbers - Chinese, the number represents the id of this list.

# Structure

```bash
.
├── Makefile
├── README.md
├── in.in
├── out.out
├── template        # any templates
├── contest	    # questions categorized by different contests
├── etc	            # questions that cannot be categorized
├── include	    # header file path
└── list            # luogu training list
```

# How to use
## Create
you can simply use `make id={id}` command to create a new file with the default template.

## Debug & Run
I use `vscode` and `CodeRunner` plugin to run my code.

after installing the plugin, we should modify and settings in `settings.json`.

find and modify it:

```json
"code-runner.executorMap": {
    "cpp": "cd $dir \
        && g++ $fullFileName -o $workspaceRoot/main -D DEBUG -I $workspaceRoot/include \
        && cd $workspaceRoot \
        && clear && $workspaceRoot/main \
        && rm $workspaceRoot/main && echo && echo",
}
```
Please enter the sample in the `in.in` file, then click `Run Code` in the upper right corner. You will see the output in `out.out`.

It is highly recommended to open `in.in` and `out.out` simultaneously in one vscode window, so that you can directly edit the input and view the output in real time.
