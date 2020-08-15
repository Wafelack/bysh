use std::fs;
use std::fs::File;
use std::io::{Error, ErrorKind, Write};
use std::path::Path;

fn mkdir(name: &str, errmess: &str, number: u8) {
    match fs::create_dir(name) {
        Ok(_) => (),
        Err(_e) => println!("{} - {}", number, errmess),
    }
}

pub fn reinit() -> std::io::Result<()> {
    if !Path::new("lock.wmg").exists() {
        println!("Error !");
        return Err(Error::new(ErrorKind::Other, "Not in a wanager project"));
    }
    fs::remove_dir_all("src")?;
    fs::remove_dir_all("build")?;

    let errmess: &str = "Error while creating directories";
    mkdir("src", errmess, 1);
    mkdir("build", errmess, 2);
    mkdir("build/release", errmess, 3);
    mkdir("build/debug", errmess, 4);

    let mut mf = File::create("src/main.c")?;
    mf.write_all(b"#include <stdio.h>\n")?;
    mf.write_all(b"#include <stdlib.h>\n")?;
    mf.write_all(b"\nint main(void) {\n")?;
    mf.write_all(b"    puts(\"Hello, World !\");\n")?;
    mf.write_all(b"    return EXIT_SUCCESS;\n")?;
    mf.write_all(b"}")?;
    Ok(())
}
