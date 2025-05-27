clear 
clc

b_all = [];
a_all = [];

for i=5000:5000:40000
    
    f0 = i;
    fs = 200000;
    Q = 4.5;
    w = 2*pi*f0/fs;
    alpha = sin(w) / (2*Q);
    b0 = alpha;
    b1 = 0;
    b2 = -alpha;
    alpha0 = 1 + alpha;
    alpha1 = -2*cos(w);
    alpha2 = 1 - alpha;
    B0 = b0 / alpha0;
    B1 = b1 / alpha0;
    B2 = b2 / alpha0;
    A1 = alpha1 / alpha0;
    A2 = alpha2 / alpha0;
    
    
    b = [B0, B1, B2];
    a = [1, A1, A2];
    [h, w] = freqz(b, a, 128);
    
    b_all = [b_all; b];
    a_all = [a_all; a];

    hold on
    plot(w/pi, mag2db(abs(h)))
    hold off
    title('Frequency Response of IIR Filter for Normalized Frequencies')
    xlabel('Normalized Frequency') 
    ylabel('Filter Gain(db)') 
    
end

