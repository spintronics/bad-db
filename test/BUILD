load("@rules_cc//cc:defs.bzl", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_test(
    name = "file_test",
    size = "small",
    srcs = ["file_test.cc"],
    deps = [
        "//lib:file",
        "@com_google_googletest//:gtest_main",
    ],
)
