if(EXISTS "/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_original/build/functional-tests-b12d07c_tests.cmake")
  include("/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_original/build/functional-tests-b12d07c_tests.cmake")
else()
  add_test(functional-tests_NOT_BUILT-b12d07c functional-tests_NOT_BUILT-b12d07c)
endif()