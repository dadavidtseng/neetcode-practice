impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut result: i32 = 0;
        let tokens_size = tokens.len();
        let mut s: Vec<i32> = Vec::new();

        for i in 0..tokens_size
        {
            if tokens[i] == "+"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b + a;
                s.push(result);
            }
            else if tokens[i] == "-"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b - a;
                s.push(result);
            }
            else if tokens[i] == "*"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b * a;
                s.push(result);
            }
            else if tokens[i] == "/"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b / a;
                s.push(result);
            }
            else
            {
                let t = tokens[i].parse().unwrap();
                result = t;
                s.push(t);
            }
        }

        result
    }
}
