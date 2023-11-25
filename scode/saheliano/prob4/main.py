from math import *
def read_inputs():
    line = input().split()
    return list(map(lambda x: int(x), line))


action = lambda f, v : (f[0]+v[0], f[1]+v[1])
hyper  = lambda v : sqrt(v[0]**2+v[1]**2)

def new_action(from_, v, to_):

    signe_vx = 1 if (v[0] > 0 and (to_[1] in [0, h])) or (to_[0]==0) else -1
    signe_vy = 1 if (v[1] > 0 and (to_[0] in [0, l])) or (to_[1]==0) else -1

    #print(f'{to_} signe_vx {signe_vx} signe_vy {signe_vy}')
    ac_ = h if to_[1] in [0, h] else l
    ab_ = abs(ac_ * hyper(v) / v[1])
    bc_ = abs(ab_ * (v[0]/ hyper(v)))

    #print(f'ac {ac_} bc {bc_}, ab {ab_}')
    if ((bc_* signe_vx)+ to_[0] >l or  (bc_* signe_vx)+ to_[0] <0):
        #print("hiiii else")
        bc = (l-to_[0]) if (bc_* signe_vx)+ to_[0] > l else to_[0]
        ab = ab_ * bc / bc_
        ac = sqrt(ab ** 2 - bc ** 2)
    elif (bc_* signe_vy)+ to_[1] >h or  (bc_* signe_vy)+ to_[1] <0:
        #print("hiiii elif")
        bc = (h - to_[1]) if (bc_ * signe_vx) + to_[1] > h else to_[1]
        ab = ab_ * bc / bc_
        ac = sqrt(ab ** 2 - bc ** 2)
    else:
        bc = bc_
        ab = ab_
        ac = ac_

    #print((bc* signe_vx, ac*signe_vy))
    return (bc* signe_vx, ac*signe_vy)

if __name__ == '__main__':
    l, h, x, y, vx, vy, K = read_inputs()
    from_ = (x, y)
    v = (vx, vy)

    to_ = action(from_, v)

    for i in range(1, K):
        new_action_ = new_action(from_, v, to_)
        from_ = to_
        v = new_action_
        to_ = action(from_, v)

    print(f'{round(to_[0])} {round(to_[1])}')