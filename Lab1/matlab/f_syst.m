function v = f_syst(xy)
    x = xy(1);
    y = xy(2);

    v(1) = x.^2 + y.^2 - 5;
    v(2) = y - exp(-x.*y);
end
