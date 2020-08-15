use std::process::Command;

pub fn build() {
    Command::new("gcc")
        .arg("src/*.c")
        .arg("-o")
        .arg("build/release/release.exe")
        .arg("-W")
        .arg("-Wall")
        .arg("-Werror")
        .arg("-Wextra")
        .spawn()
        .expect("Error while running compilation command.");
}
pub fn buildhard() {
    Command::new("gcc")
        .arg("src/*.c")
        .arg("-o")
        .arg("build/debug/debug.exe")
        .spawn()
        .expect("Error while running compilation command.");
}
