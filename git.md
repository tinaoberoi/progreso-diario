##### Removing multiple files rather than using git rm again n again
```
git ls-files --deleted -z | xargs -0 git rm
```