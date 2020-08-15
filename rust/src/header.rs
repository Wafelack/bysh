use std::fs::File;
use std::io::Write;

pub fn header(name: &str) -> std::io::Result<()> {
    let mut filename = String::from(name);
    filename.push_str(".h");

    let mut ifndef = String::from("#ifndef _");
    ifndef.push_str(&name.to_uppercase());
    ifndef.push_str("_H_\n");

    let mut define = String::from("#define _");
    define.push_str(&name.to_uppercase());
    define.push_str("_H_\n\n\n\n");

    let mut endif = String::from("#endif /* _");
    endif.push_str(&name.to_uppercase());
    endif.push_str("_H_ */\n");

    let mut fic = File::create(filename)?;
    fic.write_all(ifndef.as_bytes())?;
    fic.write_all(define.as_bytes())?;
    fic.write_all(endif.as_bytes())?;

    Ok(())
}
