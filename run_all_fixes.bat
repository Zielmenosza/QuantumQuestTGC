@echo off

echo Running all fixes...

call cleanup_unnecessary_files.sh
call create_missing_files.sh
call check_gradle.sh
call fix_pathing_issues.sh
call run_clean_build.sh

echo All tasks completed.
