# Description
This project registers users and then let them to login with correct username and password

## Fast run

Install [bazel](https://docs.bazel.build/versions/main/install.html).

run
```bash
bazel run //main:login-registration
```

## Tests

user_test
```bash
bazel test --test_output=all //libraries/test:user_test
```

## format BUILD files

```bash
bazel run //:buildifier
```
