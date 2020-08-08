use std::fs;
use std::fs::File;
use std::io::Write;

fn mkdir(name: &str, errmess: &str, number: u8) {
    match fs::create_dir(name) {
        Ok(_) => (),
        Err(_e) => println!("{} - {}", number, errmess),
    }
}

pub fn create(name: &str) -> std::io::Result<()> {
    let errmess: &str = "Error in process. Please retry later";

    let mut src: String = name.into();
    src.push_str("\\src");

    let mut build: String = name.clone().into();
    build.push_str("\\build");

    let mut release: String = build.clone();
    release.push_str("\\release");

    let mut debug: String = build.clone();
    debug.push_str("\\debug");

    let mut main: String = src.clone();
    main.push_str("\\main.c");

    mkdir(name, errmess, 1);
    mkdir(&src, errmess, 2);
    mkdir(&build, errmess, 3);
    mkdir(&release, errmess, 4);
    mkdir(&debug, errmess, 5);

    let mut mf = File::create(main)?;
    mf.write_all(b"#include <stdio.h>\n")?;
    mf.write_all(b"#include <stdlib.h>\n")?;
    mf.write_all(b"int main(void) {\n")?;
    mf.write_all(b"    puts(\"Hello, World !\");\n")?;
    mf.write_all(b"    return EXIT_SUCCESS;\n")?;
    mf.write_all(b"}")?;

    let mut lock: String = name.clone().into();
    lock.push_str("\\lock.wmg");

    let mut locker = File::create(lock)?;
    locker.write_all(b"DON'T DELETE IMPORTANT FILE")?;

    Ok(())
}
